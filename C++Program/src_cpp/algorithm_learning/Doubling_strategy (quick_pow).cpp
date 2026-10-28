/*
洛谷（https://www.luogu.com.cn/problem/P1226）

题目描述：
给你三个整数 a, b, p，求 a^b mod p。

输入格式：
输入只有一行三个整数，分别代表 a, b, p。

输出格式：
输出一行一个字符串 a^b mod p=s，其中 a, b, p 分别为题目给定的值，s 为运算结果。
*/
#include<iostream>

typedef long long ll;
using namespace std;

ll powMod(ll a, ll b, ll p);

int main(){
    ll a, b, p;
    cin >> a >> b >> p;

    cout << powMod(a, b, p) << endl;
}

ll powMod(ll a, ll b, ll p){
    ll mod = 1;

    while (b){
        //取余对于加减法和乘法是同余的，但是注意负数的余数在程序里是一个负数，可用加被除数法取正
        if (b & 1) mod = mod * a % p;
        //在计算余数时，无论在哪里添加取余符号，都不改变最终取余结果（乘法或加减法）
        a = a * a % p;
        //采用二进制来获取是否要乘这个数
        b >>= 1;
    }
    return mod;
}
