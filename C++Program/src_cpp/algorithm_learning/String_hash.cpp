/*
洛谷（https://www.luogu.com.cn/problem/P3370）

题目描述：
如题，给定 N 个字符串（第 i 个字符串长度为 Mi，字符串内包含数字、大小写字母，大小写敏感），请求出 N 个字符串中共有多少个不同的字符串。

输入格式：
第一行包含一个整数 N，为字符串的个数。
接下来 N 行每行包含一个字符串，为所提供的字符串。

输出格式：
输出包含一行，包含一个整数，为不同的字符串个数。
*/
//字符串哈希常用于处理子串问题和不同字符串问题
//通过将字符串映射为一个 P 进制下的无符号整数，再比较有多上个不同的整数从而解决问题
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10, P = 13331;
typedef unsigned long long ULL;

ULL preSum[N] = {0};

string s;
int hashTab[N] = {0};
int len;

ULL getHash(string s);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> len;
    for (int i = 0; i < len; i++){
        cin >> s;
        hashTab[i] = getHash(s);
    }

    int diffNum = 1;
    sort(hashTab, hashTab + len);
    for (int i = 0; i < len - 1; i++){
        if (hashTab[i] < hashTab[i + 1]){
            diffNum++;
        }
    }

    cout << diffNum << endl;
}

/* 
如果要输出一段字符串任意子串的哈希值，那么可以先初始化前缀哈希表
再来获取，降低时间复杂度 
*/
// void initHash(strng s){
//     preSum[0] = 0; pow[0] = 1;
//
//     for(int i = 1; i <= s.size(); i++){
//         preSum[i] = preSum[i - 1] * P + s[i];
//         pow[i] = pow[i] * P;
//     }
// }

ULL getHash(string s){
    for(int i = 1; i <= s.size(); i++){
        preSum[i] = preSum[i - 1] * P + s[i];
    }
    return preSum[s.size()];
}