/*
描述
输入两个整数，求这两个整数的和是多少。

输入
输入两个整数A,B，用空格隔开
0≤A,B≤10^8

输出
输出一个整数，表示这两个数的和
*/
#include<iostream>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}