/*
描述
维护一个集合，支持如下几种操作：
1. “I x”，插入一个数 x；
2. “Q x”，询问数 x 是否在集合中出现过；
现在要进行 N 次操作，对于每个询问操作输出对应的结果。

数据范围：
1≤N≤10^5
−10^9≤x≤10^9

输入
第一行包含整数 N，表示操作数量。
接下来 N 行，每行包含一个操作指令，操作指令为“I x”，“Q x”中的一种。

输出
对于每个询问指令“Q x”，输出一个询问结果，如果 x 在集合中出现过，则输出“Yes”，否则输出“No”。
每个结果占一行。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<int>> table;
char oper;
int x;

bool check(int x){
    int j = x >= 0 ? x % N : ((x % N) + N) % N;
    if (table[j].empty()){
        return false;
    }
    for (auto i : table[j]){
        if (i == x){
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    table.resize(N);
    for (int i = 0; i < N; i++){
        cin >> oper >> x;

        if (oper == 'I'){
            table[x >= 0 ? x % N : ((x % N) + N) % N].push_back(x);
        }else if (oper == 'Q'){
            //再输出内容较多的情况下 \n 比 endl 快
            cout << (check(x) ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}

