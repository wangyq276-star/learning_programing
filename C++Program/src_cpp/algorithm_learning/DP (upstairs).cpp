/*
洛谷（https://www.luogu.com.cn/problem/P10250）

题目描述：
顽皮的小明发现，下楼梯时每步可以走 1 个台阶、2 个台阶或 3 个台阶。现在一共有 N 个台阶，你能帮小明算算有多少种方案吗？

输入格式：
输入一行，包含一个整数 N。

输出格式：
输出一行一个整数表示答案。
*/
#include<iostream>
using namespace std;
typedef unsigned long long ull;

const int N = 1e6 +10;
ull a[N] = {1, 2, 4};
int n;

ull methods(int n){
    if ( n == 1 || n == 2){
        return a[n - 1];
    }

    for (int i = 3; i < n + 1; i++){
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }

    return a[n - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << methods(n) << endl;
}