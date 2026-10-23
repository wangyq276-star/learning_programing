/*
洛谷（https://www.luogu.com.cn/problem/P1115）

题目描述
给出一个长度为 n 的序列 a，选出其中连续且非空的一段，使得这段和最大。

输入格式
第一行是一个整数 n，表示序列的长度。
第二行有 n 个整数，第 i 个整数表示序列的第 i 个数字 ai。

输出格式
输出一行一个整数，表示答案
*/
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

//数列中项的个数和数列数组存储
int n;
int a[N] = {0};

void findMaxSub(int* arr);

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    findMaxSub(a);

}

//写一个函数实现找到最大子列
void findMaxSub(int* srr){

}