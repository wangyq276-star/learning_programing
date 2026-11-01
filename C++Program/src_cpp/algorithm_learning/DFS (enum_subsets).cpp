/*
洛谷（https://www.luogu.com.cn/problem/B3622）

题目描述：
今有 n 位同学，可以从中选出任意名同学参加合唱。请输出所有可能的选择方案。

输入格式：
仅一行，一个正整数 n。

输出格式：
若干行，每行表示一个选择方案。
每一种选择方案用一个字符串表示，其中第 i 位为 Y 则表示第 i 名同学参加合唱；为 N 则表示不参加。
需要以字典序输出答案。
*/
//本题亦可采用二进制枚举算法实现，以下使用深度优先遍历
#include<iostream>
#include<string>

using namespace std;

string path;

void DFSchoice(string path, int pos, int level);

int main(){
    int n;
    cin >> n;
    DFSchoice(path, 1, n);

}

void DFSchoice(string path, int pos, int choice){
    //递归出口，当 pos 大于需要排列的人的总数时，就可以打印出每个人的选择（当前路径），然后退出
    if (pos > choice){
        cout << path << endl;
        return;
    }
    //第一种选择：不去，然后递归看下一个人去不去
    path += 'N';
    DFSchoice(path, pos + 1, choice);
    //递归结束后一定要记得恢复初始状态（也就是回溯减枝）
    path.pop_back();

    //同理，第二种选择：去，然后看下一个人
    path += 'Y';
    DFSchoice(path, pos + 1, choice);
    path.pop_back();

}