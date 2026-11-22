/*
描述
要寻找克罗克果实，林克需要把苹果放在盘子里
其中只有一种情况可以让克罗克果实出现。所以，林克需要尝试所有的放法。
有M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的放法？
注意：5，1，1和1，5，1 是同一种放法。

输入
第一行是测试数据的数目t（0 <= t <=20）。
以下每行均包含二个整数M和N，以空格分开。
1 <= M，N <= 10。

输出
对输入的每组数据M和N，用一行输出相应的K。K为正整数，代表共有几种放法。
*/
// 因为需要不同的分法，所以组合数这里不适用，可以看为一个整数 m 的 n 拆分问题
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m, n;
int a[N] = {0};
int c = 0;

int sum(int pos) {
    int s = 0;
    for (int i = 0; i <= pos; i++) {
        s += a[i];
    }
    return s;
}

void dfs(int pos) {
    if (pos == n) {
        if (sum(n - 1) == m) {
            c++;
        }

        return;
    }

    for (int i = 0; i <= m; i++) {
        if ((pos != 0 && sum(pos - 1) + (n - pos) * i > m) ||
            (pos != 0 && a[pos - 1] > i)) {
            continue;
        }
        a[pos] = i;
        dfs(pos + 1);
        a[pos] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        c = 0;
        cin >> m >> n;
        dfs(0);
        cout << c << '\n';
    }

    return 0;
}