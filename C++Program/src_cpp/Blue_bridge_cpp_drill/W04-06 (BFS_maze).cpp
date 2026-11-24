/*
描述
给定一个n*m的二维整数数组，用来表示一个迷宫
数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。
最初，有一个人位于左上角(1, 1)处
已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角(n, m)处，至少需要移动多少次。
数据保证(1, 1)处和(n, m)处的数字为0，且一定至少存在一条通路。
数据范围：1<=n<=10

输入
第一行包含两个整数n和m。
接下来n行，每行包含m个整数（0或1），表示完整的二维数组迷宫。

输出
输出一个整数，表示从左上角移动至右下角的最少移动次数。
*/
#include <iostream>
#include <queue>
using namespace std;

const int N = 100;
int maze[N][N] = {0};
queue<pair<int, int>> q;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int n, m;

void bfs() {
    q.push({0, 0});
    maze[0][0] = 0;

    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        if (i == n - 1 && j == m - 1) {
            return;
        }

        for (int k = 0; k < 4; k++) {
            int x = i + di[k], y = j + dj[k];
            if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != -1) {
                continue;
            }
            maze[x][y] = maze[i][j] + 1;
            q.push({x, y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; i < m; i++) {
            int k;
            cin >> k;
            maze[i][j] = k == 0 ? -1 : 1;
        }
    }

    bfs();
    cout << maze[n - 1][m - 1] << endl;
    return 0;
}