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

//引入前缀和来解决问题
//数列中项的个数和前缀和数组存储
int n;
long long a[N] = {0};

void findMaxSub(long long* arr, int n);

int main(){
    cin >> n;

    int total = 0, t;

    for (int i = 0; i < n; i++){
        cin >> t;
        total += t;
        a[i + 1] = total;
    }

    findMaxSub(a, n);

}

//写一个函数实现找到最大子列和
void findMaxSub(long long* arr, int len){
    //运用擂台比较的方式得到
    int max = arr[0];
    int tol = 0;
    int left, right;

    for (int i = 1; i < len; i++){
        for (int j = i; j < len; j++){
            tol = arr[j] - arr[i - 1];
            if (tol > max){
                max = tol;
                left = i;
                right = j;
            }
        }
    }
    cout << "The max subarray is from " << left << " to " << right <<endl;
    cout << "Max is " << max << endl;
    
}

/*
测试用例
7
2 -4 3 -1 2 -4 3 

The max subarray is from 3 to 5
Max is 4
*/