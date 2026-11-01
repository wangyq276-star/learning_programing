/*
洛谷（https://www.luogu.com.cn/problem/P10448）

题目描述：
从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。

输入格式：
两个整数 n,m，在同一行用空格隔开。

输出格式：
按照从小到大的顺序输出所有方案，每行 1 个。
同一行内的数升序排列，相邻两个数用一个空格隔开。
对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> path;

void DFScombin(vector<int> path, int start, int end, int choice);
void showVector(vector<int> List);

int main(){
    int n, m;
    cin >> n >> m;
    DFScombin(path, 1, n, m);
}

void DFScombin(vector<int> path, int start, int end, int choice){
    if (path.size() == choice){
        showVector(path);
        return;
    }

    //每次开头的那个已经固定，余下的序列依靠递归去找，一定要画一下决策树
    for (int i = start; i <= end; i++){
        path.push_back(i);
        DFScombin(path, i + 1, end, choice);
        path.pop_back();
    }
}

void showVector(vector<int> List){
    for (int i = 0; i < List.size(); i++){
        cout << List[i] << ' ';
    }
    cout << endl;
}

/*
测试用例

4 3
1 2 3 
1 2 4 
1 3 4 
2 3 4 

6 3
1 2 3 
1 2 4 
1 2 5 
1 2 6 
1 3 4 
1 3 5 
1 3 6 
1 4 5 
1 4 6 
1 5 6 
2 3 4 
2 3 5 
2 3 6 
2 4 5 
2 4 6 
2 5 6 
3 4 5 
3 4 6 
3 5 6 
4 5 6 

*/