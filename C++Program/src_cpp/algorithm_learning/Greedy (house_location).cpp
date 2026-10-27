/*
洛谷（https://www.luogu.com.cn/problem/P10452）

题目描述：
在一条数轴上有 N 家商店，它们的坐标分别为 A₁ ∼ Aₙ。
现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

输入格式：
第一行输入整数 N。
第二行输入 N 个整数 A₁ ∼ Aₙ。

输出格式：
输出一个整数，表示距离之和的最小值。
*/

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
//商店的数量
int n;

//商店的坐标
int loca[N];

int findMinSum(int* List, int len);

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> loca[i];
    }

    cout << findMinSum(loca, n) << endl;
}

int findMinSum(int* List, int len){
    /* 
    本题最关键的一步就是把货仓的位置设为所有数中位数的位置
    贪心策略就是认为该位置是到所有位置距离之和最小的位置
    其实数学上就是取一系列绝对值之和的最小值
    对于从外到内，每次取对应两个点，可以证明当且仅当该点在这两个端点之间时，距离最小
    也就是说该点要尽可能在所有对应两点的中间位置
    */
    int mid = List[(len - 1) >> 1];

    int total = 0;
    for (int i = 0; i < len; i++){
        total += abs(List[i] - mid);
    }
    return total;
}