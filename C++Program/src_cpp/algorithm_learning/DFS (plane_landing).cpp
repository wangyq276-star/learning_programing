/*
洛谷（https://www.luogu.com.cn/problem/P9241）

题目描述：
N 架飞机准备降落到某个只有一条跑道的机场。
其中第 i 架飞机在 Ti 时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 Di 个单位时间。
即它最早可以于 Ti 时刻开始降落，最晚可以于 Ti + Di 时刻开始降落。
降落过程需要 Li 个单位时间。
一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。
请你判断 N 架飞机是否可以全部安全降落。

输入格式：
输入包含多组数据。
第一行包含一个整数 T，代表测试数据的组数。
对于每组数据，第一行包含一个整数 N。
以下 N 行，每行包含三个整数 Ti, Di, Li。

输出格式：
对于每组数据，输出 YES 或者 NO，代表是否可以全部安全降落
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 100;

int T[N] = {0}, D[N] = {0}, L[N] = {0};
int n;
int land[N] = {0};

bool DFSlandSafe(int landed, int time);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        //记得清空数据防止污染
        memset(land, 0, sizeof(land));
        memset(T, 0, sizeof(land));
        memset(D, 0, sizeof(land));
        memset(L, 0, sizeof(land));
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> T[j] >> D[j] >> L[j];
        }
        if (DFSlandSafe(0, 0)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        } 
    }
    
}

/* 参数列表有 已经降落的飞机数量 和 理论最早降落时刻 */
bool DFSlandSafe(int landed, int time){
    if (landed >= n){
        return true;
    }

    //这里 for 循环加上 if 的判断，相当于构成了这 N 架飞机的全排列
    for (int i = 0; i < n; i++){
        /*
        可行性减枝：
        1.当此架飞机已经降落就必定不合法了
        2.如果下一架飞机的理论最早降落时刻比最迟的合法降落时刻还迟，那么也不合法
        */
        if (land[i] || time > T[i] + D[i]){
            continue;  
        }

        /*
        下面是标准的 DFS 模板：
        1.进入分支（通常是修改参数的值）
        2.深度优先，遍历下方的子分支 -> 对于子分支依旧有这三个步骤直到叶子节点
        3.退出分支（将参数的值恢复原样）
        */
        land[i] = true;
        if (DFSlandSafe(landed + 1, max(time, T[i]) + L[i])){
            return true;
        };
        land[i] = false;
    }

    return false;
}
