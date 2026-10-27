/*
洛谷（https://www.luogu.com.cn/problem/P1115）

题目描述：
给出一个长度为 n 的序列 a，选出其中连续且非空的一段使得这段和最大。

输入格式：
第一行是一个整数，表示序列的长度 n。
第二行有 n 个整数，第 i 个整数表示序列的第 i 个数字 a_i。

输出格式：
输出一行一个整数表示答案。
*/

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
//商店的数量
int n;

//商店的坐标
int loca[N];

int findMinSum(int* List, int len);

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> loca[i];
    }

    cout << findMinSum(loca, n) << endl;
}