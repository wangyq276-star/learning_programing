/*
描述
随着编程水平的进阶，小华知道是全面扩充小鲁知识面，帮助他快速升级的时候到了
他再给小鲁布置了道经典题：
输入一个正整数N，请写一个程序，输出N皇后问题的全部摆法。

输入
输入皇后的个数n（n<=13）

输出
输出长度为n的正整数。
输出结果里的每一行都代表一种摆法。
行里的第i个数字如果是n，就代表第i行的皇后应该放在第n列。
皇后的行、列编号都是从1开始算。
*/
#include <iostream>
using namespace std;

int a[20];
int n;

int c[20], l[50], r[50];

void dfs(int pos) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << '\n';
        return;
    }
    for (int j = 0; j < n; j++) {
        if (c[j] || l[pos - j + n] || r[pos + j]) {
            continue;
        }
        c[j]++;
        l[pos - j + n]++;
        r[pos + j]++;
        a[pos] = j + 1;
        dfs(pos + 1);
        a[pos] = 0;
        c[j]--;
        l[pos - j + n]--;
        r[pos + j]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dfs(0);

    return 0;
}