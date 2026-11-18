/*
描述
你玩过“拉灯”游戏吗？
25盏灯排成一个5×5的方形。
每一个灯都有一个开关，游戏者可以改变它的状态。
每一步，游戏者可以改变某一个灯的状态。
游戏者改变一个灯的状态会产生连锁反应：和这个灯上下左右相邻的灯也要相应地改变其状态。
我们用数字1表示一盏开着的灯，用数字0表示关着的灯。
下面这种状态

10111
01101
10111
10000
11011

在改变了最左上角的灯的状态后将变成：

01111
11101
10111
10000
11011

再改变它正中间的灯后状态将变成：

01111
11001
11001
10100
11011

给定一些游戏的初始状态，编写程序判断游戏者是否可能在6步以内使所有的灯都变亮。

输入
第一行输入正整数n，代表数据中共有n个待解决的游戏初始状态。
以下若干行数据分为n组，每组数据有5行，每行5个字符。
每组数据描述了一个游戏的初始状态。
各组数据间用一个空行分隔。

数据范围：
0<n≤500

输出
一共输出n行数据，每行有一个小于等于6的整数，
它表示对于输入数据中对应的游戏状态最少需要几步才能使所有灯变亮。
对于某一个游戏初始状态，若6步以内无法使所有灯变亮，则输出−1。
*/
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int lit[5][5];

void change(int (&List)[5][5], int i, int j) {

    const static int di[5] = {0, 1, -1, 0, 0};
    const static int dj[5] = {0, 0, 0, 1, -1};

    if (!(i >= 0 && i <= 4 && j >= 0 && j <= 4)) {
        return;
    }

    for (int t = 0; t < 5; t++) {
        int x = i + di[t], y = j + dj[t];
        if (x >= 0 && x <= 4 && y >= 0 && y <= 4) {
            List[x][y] = !List[x][y];
        }
    }

    return;
}

int checkTime() {
    int total = 0;
    int minTotal = 100;
    int copy[5][5];

    for (int i = 0; i < (1 << 5); i++) {
        total = 0;
        memcpy(copy, lit, sizeof(lit));

        for (int j = 0; j < 5; j++) {
            if ((i >> j) & 1) {
                change(copy, 0, j);
                total++;
            }
        }

        for (int m = 0; m < 4; m++) {
            for (int n = 0; n < 5; n++) {
                if (!copy[m][n]) {
                    change(copy, m + 1, n);
                    total++;
                }
            }
        }

        if (total <= 6) {
            bool ok = true;

            for (int t = 0; t < 5; t++) {
                if (copy[4][t]) {
                    continue;
                }
                ok = false;
            }

            if (ok) {
                minTotal = min(minTotal, total);
            }
        }
    }

    if (minTotal <= 6) {
        return minTotal;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string s;

        for (int i = 0; i < 5; i++) {
            cin >> s;
            for (int j = 0; j < 5; j++) {
                lit[i][j] = s[j] - '0';
            }
        }

        cout << checkTime() << '\n';
    }
    return 0;
}
