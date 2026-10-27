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

//理论上可以使用前缀和，此处使用贪心策略解决
#include<iostream>
using namespace std;

const int N = 2e5 + 10;

int n;

int a[N];

//注意数据范围，是否溢出，这种求和问题用long long比较保险
long long findMaxSum(int* List, int len);

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << findMaxSum(a, n) << endl;
}

long long findMaxSum(int* List, int len){
    long long maxSum = List[0], S = List[0];

    for (int i = 1; i < len; i++){

        //如果 S 对下一个数相加的和有贡献，那么就加上，如果没有贡献，就从下一个开始累计
        S = (S + List[i] > List[i]) ? (S + List[i]) : List[i];

        //使用 maxSum 保存所有累计的 S 中最大的那个
        maxSum = S > maxSum ? S : maxSum;
    }

    return maxSum;
}