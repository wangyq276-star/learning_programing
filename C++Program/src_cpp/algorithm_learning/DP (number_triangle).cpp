/*
洛谷（https://www.luogu.com.cn/problem/P1216）

题目描述：
观察下面的数字金字塔。
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。
每一步可以走到左下方的点也可以到达右下方的点。
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
在上面的样例中，从 7 → 3 → 8 → 7 → 5 的路径产生了最大权值。

输入格式：
第一个行一个正整数 r，表示行的数目。
后面每行为这个数字金字塔特定行包含的整数。

输出格式：
单独的一行，包含那个可能得到的最大的和。
*/
#include <iostream>
using namespace std;

int r;
const int N = 1010;
int f[N][N] = {{0}};

int findWayMax(){
    for (int i = 1; i < r; i++){
        for (int j = 0; j <= i; j++){
            if (i == j){
                f[i][j] += f[i - 1][j - 1];
            }else{
                f[i][j] = max(f[i][j] + f[i - 1][j - 1], f[i][j] + f[i - 1][j]);
            }
        }
    }

    int maxNum = f[r - 1][0];
    for (int j = 1; j < r; j++){
        maxNum = max(f[r - 1][j], maxNum);
    }

    return maxNum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r;
    for (int i = 0; i < r; i++){
        for (int j = 0; j <= i; j++){
            cin >> f[i][j];
        }
    }

    cout << findWayMax() << endl;

    return 0;
}