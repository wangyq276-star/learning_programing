/*
牛客网（https://www.nowcoder.com/practice/4bbc401a5df140309edd6f14debdba42）

题目描述：
对于给定的长度为 n 的数组 {a1, a2, ..., an}，有 m 次修改操作。每一次操作给出三个参数 l, r, k，代表将数组中的 a(l), a(l+1), ..., ar 都加上 k。
请你直接输出全部操作完成后的数组。

输入描述：
第一行输入两个整数 n, m（1 <= n, m <= 10^5），代表数组中的元素数量、操作次数。
第二行输入 n 个整数 a1, a2, ..., an（-10^9 <= ai <= 10^9），代表初始数组。
此后 m 行，每行输入三个整数 l, r, k（1 <= l <= r <= n；-10^9 <= k <= 10^9），代表一次操作。

输出描述：
在一行上输出 n 个整数，代表全部操作完成后的数组。
*/
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
long d[N] = {0};
int n;



void diff(int left, int right, long* arr, int k);

int main(){
    int a_n_ = d[0];
    int a_n;
    //操作次数
    int m;

    //操作区间和操作数
    int l, r, k;

    cin >> n >> m;

    //差分的原理就是保存每个元素与前一个元素的差
    //这样如果要对一个区间内的数据进行同加同减，只需要进行两次操作即可
    for (int i = 0; i < n; i++){
        cin >> a_n;
        d[i + 1] = a_n - a_n_;
        a_n_ = a_n;
    }

    for (int i = 0; i < m; i++){
        cin >> l >> r >> k;
        diff(l, r, d, k);
    }
}

//写一个函数返回对一个区间进行同加或同减的结果
void diff(int left, int right, long* arr, int k){
    //只需要对首尾两部分进行更改即可
    arr[left] += k;
    arr[right + 1] -= k;
    
    int a_n = arr[0];
    for (int i = 0; i < n; i++){
        a_n += arr[i + 1];
        cout << a_n << ' ';
    }
}