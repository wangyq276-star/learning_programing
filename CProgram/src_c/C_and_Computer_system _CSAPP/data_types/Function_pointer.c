/*
    指针不仅可以用于 short int long char float 等基本变量类型和 struct int[]
   等引用变量类型的地址存储
    还可以用于存储函数中第一条指令的地址，即实现指向函数\
    然后就可以使用该指针来调用该函数
    示例代码如下：
*/
int fun(int x, int *y) { return x + *y; }

// 创建一个指向函数的指针
int (*fun_ptr)(int x, int *y) = fun;

int main() {
    int y = 1;
    int result = fun_ptr(3, &y);
}