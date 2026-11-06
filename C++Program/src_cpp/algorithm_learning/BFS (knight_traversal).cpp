/*
洛谷（https://www.luogu.com.cn/problem/P1443）

题目描述：
有一个 n × m 的棋盘，在某个点 (x, y) 上有一个马，要求你计算出马到达棋盘上任意一个点最少要走几步。

输入格式：
输入只有一行四个整数，分别为 n, m, x, y。

输出格式：
一个 n × m 的矩阵，代表马到达某个点最少要走几步。不能到达则输出 -1。
*/

//广度（宽度）优先搜索是基于队列实现的
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int N = 512;

//这是棋盘和处理队列
int dist[N][N];
queue<pair<int, int>> nope;

//棋盘的大小
int n, m;
//初始原点
int x, y;

//常见技巧：设置方向数组来确定遍历方向和范围
int di[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dj[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void BFS();
void showDist();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //初始化棋盘
    memset(dist, -1, sizeof(dist));

    cin >> n >> m >> x >> y;

    BFS();
    showDist();
}

void BFS(){
    nope.push({x, y});
    //定义原点
    dist[x][y] = 0;

    while(!nope.empty()){

        int i = nope.front().first, j = nope.front().second;
        nope.pop();

        for(int k = 0; k < 8; k++){
            //减枝，把越界和曾经已经遍历过的点跳过
            if (i + di[k] < 1 || i + di[k] > n || j + dj[k] < 1 || j + dj[k] > m || dist[i + di[k]][j + dj[k]] != -1){
                continue;
            }

            dist[i + di[k]][j + dj[k]] = dist[i][j] + 1;
            //不断把下一步更新到队列中
            /* 为什么使用队列：保证先进先出，宽度优先遍历的层级顺序不会颠倒 */
            nope.push({i + di[k], j + dj[k]});
        }
    }
}

void showDist(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
}
/*
测试用例：
10 10
5 5
4 3 2 3 2 3 2 3 4 3 
3 2 3 2 3 2 3 2 3 4 
2 3 4 1 2 1 4 3 2 3 
3 2 1 2 3 2 1 2 3 4 
2 3 2 3 0 3 2 3 2 3 
3 2 1 2 3 2 1 2 3 4 
2 3 4 1 2 1 4 3 2 3 
3 2 3 2 3 2 3 2 3 4 
4 3 2 3 2 3 2 3 4 3 
3 4 3 4 3 4 3 4 3 4 
*/