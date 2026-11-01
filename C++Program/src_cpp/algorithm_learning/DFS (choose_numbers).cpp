/*
洛谷（https://www.luogu.com.cn/problem/P1036）

题目描述：
已知 n 个整数 x1, x2, ..., xn，以及 1 个整数 k（k < n）。
从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。例如当 n = 4，k = 3，4 个整数分别为 3, 7, 12, 19 时，可得全部的组合与它们的和为：
3 + 7 + 12 = 22
3 + 7 + 19 = 29
7 + 12 + 19 = 38
3 + 12 + 19 = 34
现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：3 + 7 + 19 = 29。

输入格式：
键盘输入，格式为：
n, k（1 <= n <= 20，k < n）
x1, x2, ..., xn（1 <= xi <= 5000000）

输出格式：
屏幕输出，格式为：
1 个整数（满足条件的种数）。
*/
#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int nums[N] = {0};
int len = 0;
int total = 0;

void DFSfindSumPrime(int* List, int start, int end, int pos,int choice, int total);
bool isPrime(int n);

int main(){
    int len, k;
    cin >> len >> k;
    for (int i = 0; i < len; i++){
        cin >> nums[i];
    }
    DFSfindSumPrime(nums, 0, len - 1, 1, k, total);
    cout << nums[len] << endl;
}

void DFSfindSumPrime(int* List, int start, int end, int pos,int choice, int total){
    //退出路口
    if (pos > choice){
        List[end + 1] += isPrime(total);
        return;
    }

    for (int i = start; i <= end; i++){
        total += List[i];
        DFSfindSumPrime(List, i + 1, end, pos + 1, choice, total);
        total -= List[i];
    }
}

//用于判断这个数是不是质数
bool isPrime(int n){
    if (n <= 0){
        return 0;
    }
    if (n % 2 == 0){      
        return n == 2 ? 1 : 0;
    }

    //使用 i * i <= n 会比使用 sqrt() 函数来的更快一点
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

/*
测试用例

2 2
4 5
0

4 2
1 2 3 4
4

4 3
3 7 12 19
1
*/