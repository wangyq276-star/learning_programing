/*
洛谷（https://www.luogu.com.cn/problem/P5788）

题目描述：
给出项数为 n 的整数数列 a1…n。
定义函数 f(i) 代表数列中第 i 个元素之后第一个大于 ai 的元素的下标
即 f(i) = min_{i<j<=n, aj>ai} {j}。若不存在，则 f(i) = 0。
试求出 f(1…n)。

输入格式：
第一行一个正整数 n。
第二行 n 个正整数 a1…n。

输出格式：
一行 n 个整数，表示 f(1), f(2), …, f(n) 的值
*/
#include<iostream>
#include<stack>

using namespace std;
 
const int N = 1e7 + 10;

int a[N] = {0};
int n;

void findRNearBig(int* nums, int len);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    findRNearBig(a, n);
}

void findRNearBig(int* nums, int len){
    stack<int> st;
    int index[len + 5] = {0};

    for (int i = len; i >= 1; i--){
        while (!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }

        if (!st.empty()){
            index[i] = st.top();
        }

        st.push(i);
    }

    for (int i = 1; i <= len; i++){
        cout << index[i] << ' ';
    }
}