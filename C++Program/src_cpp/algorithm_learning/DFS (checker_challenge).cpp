/*
洛谷（https://www.luogu.com.cn/problem/P1219）

题目描述：
一个如下的 6×6 的跳棋棋盘，有六个棋子被放置在棋盘上。
使得每行、每列有且只有一个，每条对角线（包括两条主对角线的所有平行线）上至多有一个棋子。
上面的布局可以用序列 2 4 6 1 3 5 来描述，第 i 个数字表示在第 i 行的相应位置有一个棋子。
这只是棋子放置的一个解。请编一个程序找出所有棋子放置的解。
并把它们以上面的序列方法输出，解按字典顺序排列。
请输出前 3 个解。最后一行是解的总个数。

输入格式：
一行一个正整数 n，表示棋盘是 n×n 大小的。

输出格式：
前三行为前三个解，每个解的两个数字之间用一个空格隔开。
第四行只有一个数字，表示解的总数。
*/

#include<iostream>

using namespace std;

const int N = 50;
//用于记录每列，和每个左右对角线的占用情况
int col[N] = {0}, rdiag[N] = {0}, ldiag[N] = {0};

int DFSchecker(int step, int size);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << DFSchecker(n, n) <<endl;
}

int DFSchecker(int step, int size){
    static int solution[N] = {0};
    static int count = 0;

    if (step == 0){
        count++;
        if (count < 4){
            for (int i = 0; i < size; i++){
                cout << solution[i] + 1 << ' ';
            }
            cout << '\n';
            //打印前三个解
        }
        return 0;
    }

    //开始暴力枚举
    for (int i = 0; i < size; i++){
        //此处位可行性减枝，看看该位置是否合法
        if (col[i] || rdiag[i - (size - step)] || ldiag[i + (size - step)]){
            continue;
        }

        //非常标准的 DFS 三步走
        col[i]++; rdiag[i - (size - step)]++; ldiag[i + (size - step)]++;
        solution[size - step] = i;
        DFSchecker(step - 1, size);
        solution[size - step] = 0;
        col[i]--; rdiag[i - (size - step)]--; ldiag[i + (size - step)]--;
    }
    return count;
}
