/*
洛谷(https://www.luogu.com.cn/problem/P3406)

题目描述：

该铁路经过 N 个城市，每个城市都有一个站。
不过，由于各个城市之间不能协调好，于是乘车每经过两个相邻的城市之间（方向不限），必须单独购买这一小段的车票。
第 i 段铁路连接了城市 i 和城市 i+1 (1 ≤ i < N)。
如果搭乘的比较远，需要购买多张车票。
第 i 段铁路购买纸质单程票需要 A_i 元。

虽然一些事情没有协调好，各段铁路公司也为了方便乘客，推出了 IC 卡。
对于第 i 段铁路，需要花 C_i 元的工本费购买一张 IC 卡，然后乘坐这段铁路一次就只要扣 B_i (B_i < A_i) 元。
IC 卡可以提前购买，有钱就可以从网上买得到，而不需要亲自去对应的城市购买。
工本费不能退，也不能购买车票。每张卡都可以充值任意数额。对于第 i 段铁路的 IC 卡，无法乘坐别的铁路的车。

Uim 现在需要出差，要去 M 个城市，从城市 P₁ 出发分别按照 P₁, P₂, P₃, …, P_M 的顺序访问各个城市，
可能会多次访问一个城市，且相邻访问的城市位置不一定相邻，而且不会是同一个城市。
现在他希望知道，出差结束后，至少会花掉多少的钱，包括购买纸质车票、买卡和充值的总费用。

输入格式：
第一行两个整数，N, M。
接下来一行，M 个数字，表示 P_i。
接下来 N−1 行，表示第 i 段铁路的 A_i, B_i, C_i。

输出格式：
一个整数，表示最少花费。
*/
#include<iostream>
using namespace std;

const int N =1e5 + 10;
//总共的城市数和要去的城市数
int n, m;
//保存要去的城市
int P[N] = {0};
//保存每一段铁路的价格
int A[N];//单程票价格
int B[N];//IC卡优惠后价格
int C[N];//工本费
//保存每段路途经过的次数（运用差分）
int d[N] = {0};
//真正的次数
int times[N] = {0};

void diff(int left, int right, int* arr, int k);
int findMin(int* arr, int* A, int* B, int* C);

int main(){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        cin >> P[i];
    }

    for (int i = 0; i < n - 1; i++){
        cin >> A[i] >> B[i] >> C[i];
    }

    //对每一段区间进行累计
    int l, r;
    for (int i = 1; i < m - 1; i++){
        l = min(P[i], P[i - 1]);
        r = max(P[i], P[i - 1]);
        diff(l, r - 1, d, 1);
    }

    //还原出真实的次数
    int a_n = d[0];
    for (int i = 0; i < m; i++){
        a_n += d[i + 1];
        times[i + 1] = a_n;
    }

    findMin(times, A, B, C);
}

//直接照搬差分函数的实现
void diff(int left, int right, int* arr, int k){
    //只需要对首尾两部分进行更改即可
    arr[left] += k;
    arr[right - 1] -= k;
}

int findMin(int* arr, int* A, int* B, int* C){
    int money = 0;
    for (int i = 0; i < n - 1; i++){
        money += min(times[i] * A[i], C[i] + times[i] * B[i]);
    }
    cout << money <<endl;
    return money;
}