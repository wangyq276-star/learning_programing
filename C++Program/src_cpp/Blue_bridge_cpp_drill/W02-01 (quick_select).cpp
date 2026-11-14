/*
描述
给定一个长度为n的整数数列，以及一个整数k
请用快速选择算法求出数列的第k小的数是多少。

输入
第一行包含两个整数 n 和 k。
第二行包含 n 个整数（所有整数均在1--10^9范围内），表示整数数列。
数据范围:1≤n≤100000,1≤k≤n

输出
一个整数代表第 k 小的数
*/
#include <iostream>
using namespace std; 

const int N = 100000;

int n, k;
int a[N] = {0};

int findK(int left, int right, int rankK){
    if (left == right){
        return a[left];
    }
    
    int flag = a[left + ((right - left + 1) >> 1)];

    int mid = left, l = left, r = right;

    while (mid <= r){
        if (a[mid] == flag){
            mid++;
        }else if (a[mid] > flag){
            swap(a[mid], a[r--]);
        }else if (a[mid] < flag){
            swap(a[l++], a[mid++]);
        }
    }

    if (rankK >= l && rankK < mid){
        return flag;
    }else if (rankK < l){
        return findK(left, l - 1, rankK);
    }else{
        return findK(mid, right, rankK);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << findK(0, n - 1, k - 1) << endl;

    return 0;
}