/*
牛客网（https://www.nowcoder.com/practice/38ae72379d42471db1c537914b06d48e）

题目描述：
给定一个 n * m 的矩阵 a
从左上角开始每次只能向右或者向下走，最后到达右下角的位置
路径上所有的数字累加起来就是路径和
输出所有的路径中最小的路径和。

输入描述：
第一行输入两个正整数 n 和 m 表示矩阵 a 的长宽。
后续输入 n 行每行有 m 个数表示矩阵的每个元素。

输出描述：
输出从左上角到右下角的最小路径和。
*/
#include <iostream>
using namespace std;

const int N = 1e4 + 10;
long long map[N][N] = {{0}};
int x, y;

long long findMinSum() {
    // 初始条件设置
    for (int j = 1; j < x; j++) {
        map[0][j] += map[0][j - 1];
    }

    for (int i = 1; i < y; i++) {
        map[i][0] += map[i - 1][0];
    }

    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            // 状态转移方程：
            map[i][j] =
                min(map[i][j] + map[i - 1][j], map[i][j] + map[i][j - 1]);
        }
    }

    return map[x - 1][y - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> map[i][j];
        }
    }

    cout << findMinSum() << endl;

    return 0;
}