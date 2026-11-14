/*
描述
给定 n 个区间 [ li , ri ]，要求合并所有有交集的区间。
注意如果在端点处相交，也算有交集。
输出合并完成后的区间个数。
例如：[1,3]和[2,6]可以合并为一个区间[1,6]。

数据范围：
1≤n≤100000,
−10^9 ≤ li ≤ ri ≤ 10^9

输入
第一行包含整数n。
接下来n行，每行包含两个整数 l 和 r。

输出
共一行，包含一个整数，表示合并区间完成后的区间个数。
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> inter(n);

    for (int i = 0; i < n; i++){
        cin >> inter[i].first;
        cin >> inter[i].second;
    }

    //要先对左端点进行排序
    sort(inter.begin(), inter.end());

    long long R = inter[0].second;
    int count = 1;
    for (int i = 1; i < n; i++){
        //每次比较左端点和合并区间的右端点，如果小于等于说明有交集，可以合并
        if (inter[i].first <= R){
            R = max(inter[i].second, R);
        }else{
            //如果不行，说明没有交集，区间数加一
            count++;
            R = inter[i].second;
        }
    }

    cout << count << endl;

    return 0;
}