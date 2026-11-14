/*
描述
输入一个长度为n的整数序列。
接下来再输入m个询问，每个询问输入一对l, r。
对于每个询问，输出原序列中从第l个数到第r个数的和。

数据范围：
1≤l≤r≤n ,
1≤n,m≤100000,
−1000≤数列中元素的值≤1000

输入
第一行包含两个整数n和m。
第二行包含n个整数，表示整数数列。
接下来m行，每行包含两个整数l和r，表示一个询问的区间范围。

输出
共 m 行，每行输出一个查询结果
*/
#include <iostream>
using namespace std;

const int N = 100010;
int a[N] = {0};
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r;

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int t = 0;
        cin >> t;
        a[i] = t + a[i - 1];
    }

    for (int i = 0; i < m; i++){
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }

    return 0;
}