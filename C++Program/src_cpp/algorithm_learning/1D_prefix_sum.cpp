/*
牛客网（https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf）

题目描述：
对于给定的长度为 n 的数组 {a1, a2, ..., an}，有 m 次查询操作。每一次操作给出两个参数 l, r
你需要输出数组中第 l 到第 r 个元素之和，即 al + a(l+1) + ... + ar。

输入描述：
第一行输入两个整数 n, m（1 <= n, m <= 10^5），代表数组中的元素数量、查询次数。
第二行输入 n 个整数 a1, a2, ..., an（-10^9 <= ai <= 10^9），代表初始数组。
此后 m 行，每行输入两个整数 l, r（1 <= l <= r <= n），代表一次查询。

输出描述：
对于每一次查询操作，在一行上输出一个整数，代表区间和。
*/

#include<iostream>

using namespace std;

const int MAX =1e5 + 10;

//分别是数列的个数n与提问的次数p
int n, p;

//选取的左索引和右索引
int l, r;

//用于存储前n项和的数组
int s[MAX] = {0};

//定义一个变量，用于计算和
int a_n = 0;
int total = 0;

int main(){

    cin >> n >> p;
    
    for (int i = 0; i < n; i++){
        cin >> a_n;
        total += a_n;
        s[i] = total;
    }

    for (int i = 0; i < p; i++){
        //已经确定l < r
        cin >> l >> r;
        l--; r--;
        cout << (s[r] - s[l]) << endl;
    }

}