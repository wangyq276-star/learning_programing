/*
描述
给定一个整数n，将数字1~n排成一排，将会有很多种排列方法。
现在，请你按照字典序将所有的排列方法输出。
数据范围：1<=n<=7

输入
共一行，包含一个整数n。

输出
按字典序输出所有排列方案，每个方案占一行。
*/
#include <iostream>
using namespace std;

bool isPlace[10];
int a[10];
int n;

void dfs(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (isPlace[i]) {
            continue;
        }
        isPlace[i] = true;
        a[pos] = i;
        dfs(pos + 1);
        a[pos] = 0;
        isPlace[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dfs(0);

    return 0;
}