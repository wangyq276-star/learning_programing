/*
描述
给定一个整数 N，请你求出所有分母小于或等于 N，大小在 [0, 1] 范围内的最简分数，并按照从小到大的顺序依次输出。
例如，当 N = 5 时，所有满足条件的分数按顺序依次为：
0/1, 1/5, 1/4, 1/3, 2/5, 1/2, 3/5, 2/3, 3/4, 4/5, 1/1

输入
共一行，包含一个整数 N。
数据范围：
1 ≤ N ≤ 160

输出
按照从小到大的顺序，输出所有满足条件的分数。
每个分数占一行，格式为 a/b，其中 a 为分子，b 为分母。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//求最大公约数的函数（辗转相除法）
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<short, short>> r;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            //最大公约数是 1 说明最简
            if (gcd(i, j) == 1){
                r.push_back({j, i});
            }
        }
    }

    //此处使用 lambda 函数通过分数的值进行排序
    sort(r.begin(), r.end(), [](pair<short, short> a, pair<short, short> b){
        return (float)a.first/a.second < (float)b.first/b.second;
    });

    for (int i = 0; i < r.size(); i++){
        cout << r[i].first << '/' << r[i].second << endl;
    }
    cout << "1/1" << endl;


    return 0;
}