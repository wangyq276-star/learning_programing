# C++ 快速 IO 技巧

> `ios::sync_with_stdio(false);` 与 `cin.tie(nullptr);` 的作用、原理与使用规范。

---

## 一、两行代码

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

放在 `main` 函数的最开头，所有 `cin >>` 之前。

```cpp
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // ... 后续正常使用 cin / cout

    return 0;
}
```

全局只需加一次，后续所有 `cin` / `cout` 都享受加速。

---

## 二、第一行：`ios::sync_with_stdio(false)`

### 2.1 默认行为

C++ 的 `cin` / `cout` 与 C 的 `scanf` / `printf` 是两套独立的 IO 系统，各自有独立的缓冲区：

```text
cin  ──┐
       ├──→ 共享/协调的底层缓冲区 ──→ 实际输入
scanf ─┘
```

默认情况下两者**同步**，即每次 `cin` 读数据前都会检查 C 的输入缓冲区状态，保证混用时读入顺序与数据都正确。

### 2.2 关掉同步

```cpp
ios::sync_with_stdio(false);
```

语义：**"我保证不混用 `cin` 和 `scanf`，别再检查了。"**

关掉后两套系统各管各的：

```text
cin  ──→ C++ 私有缓冲区 ──→ 底层
scanf ──→ C 私有缓冲区   ──→ 底层
```

### 2.3 代价

**不能再混用 `cin/cout` 与 `scanf/printf`**，否则可能出现丢数据或输出乱序。

### 2.4 反例：关掉同步后混用输出

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cout << "A";
    printf("B");
    cout << "C";
    printf("D");
    return 0;
}
```

理论顺序是 `ABCD`，实际可能输出 `BDAC` 或 `BACD`。两套缓冲区各自刷新，顺序不可控。

### 2.5 反例：关掉同步后混用输入

输入：

```text
10 20
```

代码：

```cpp
ios::sync_with_stdio(false);

int a, b;
cin >> a;          // 读 10，可能把整行都吞进 C++ 缓冲区
scanf("%d", &b);   // 底层已被 cin 掏空，读不到 20
```

输出可能是 `10 0` 或脏数据。原因是 `cin` 关闭同步后会一次性从底层读一大块进私有缓冲区，`scanf` 去底层拿不到。

---

## 三、第二行：`cin.tie(nullptr)`

### 3.1 默认行为

`cin` 默认与 `cout` **绑定（tied）**，即每次 `cin` 读数据前会先强制刷新 `cout` 的缓冲区。

这是为交互式程序服务的：

```cpp
cout << "请输入数字：";
cin >> x;   // 默认会先保证上面那句提示已真正输出
```

### 3.2 关掉绑定

```cpp
cin.tie(nullptr);
```

语义：**"`cin` 不用再管 `cout`，读入前别刷缓冲区。"**

对"先全部读完、最后一次性输出"的算法题，这个自动刷新完全是浪费，关掉后可提升速度。

### 3.3 代价

**交互题（先输出再读入）不能加这行**，否则可能出现提示还没显示就等待输入的情况。

---

## 四、效果对比

以逆序对问题（n = 5 × 10⁵）为例：

| 情况 | 大致耗时 |
|------|----------|
| 不加快速 IO | 2 ~ 3 秒，可能 TLE |
| 加了快速 IO | 0.1 ~ 0.3 秒 |

数据量越大，差距越明显。

---

## 五、使用规范

| 场景 | 能否加 |
|------|--------|
| 全程只用 `cin/cout` 的算法题 | ✅ 放心加 |
| 全程只用 `scanf/printf` 的算法题 | 可加可不加，本来就不慢 |
| `cin/cout` 与 `scanf/printf` 混用 | ❌ 不能加 `sync_with_stdio(false)` |
| 交互题（先输出再读入） | ❌ 不能加 `cin.tie(nullptr)` |
| 洛谷 / 牛客 / Codeforces 普通题 | ✅ 默认加 |

**最简安全原则**：一道题里只选一套 IO 系统（全 `cin/cout` 或全 `scanf/printf`），选 `cin/cout` 就在 `main` 开头加那两行。

---

## 六、常见疑问

**Q1：为什么关掉同步会更快？**

同步本身有成本。每次 `cin` 读数据都要检查 C 缓冲区状态、协调两边位置，数据量大时累积开销可观。关掉同步等于省掉这部分检查。

**Q2：`scanf/printf` 也需要加速吗？**

`scanf/printf` 本身已经比默认的 `cin/cout` 快，通常无需额外加速。若数据量极大，可以考虑手写快读（`getchar` 版本）。

**Q3：加了快速 IO 后还能用 `endl` 吗？**

能，但不推荐。`endl` 会强制刷新缓冲区，等价于每次都 flush，抵消部分加速效果。建议改用 `'\n'`。

```cpp
cout << ans << '\n';   // 推荐
cout << ans << endl;   // 不推荐，强制 flush
```

**Q4：`cin.tie(nullptr)` 和 `cout.tie(nullptr)` 有什么区别？**

- `cin.tie(nullptr)`：解除 `cin` 对 `cout` 的绑定，影响**输入**前的刷新行为，常用。
- `cout.tie(nullptr)`：解除 `cout` 对某流的绑定，实际几乎无效（`cout` 默认未绑定），一般不需要写。

---

## 七、总结

- `ios::sync_with_stdio(false);` → 让 `cin/cout` 不再和 `scanf/printf` 同步，**加速读入**。
- `cin.tie(nullptr);` → 让 `cin` 读入前不再强制刷新 `cout`，**加速整体 IO**。
- 两行都放在 `main` 开头，普通算法题无脑加。
- **不要混用 `cin` 与 `scanf`**，交互题不要加 `cin.tie(nullptr)`。
- 输出换行优先用 `'\n'`，而非 `endl`。