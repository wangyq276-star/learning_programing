/*
洛谷（https://www.luogu.com.cn/problem/P1025）

题目描述：
将整数 n 分成 k 份，且每份不能为空，任意两个方案不相同（不考虑顺序）。
例如：n = 7，k = 3，下面三种分法被认为是相同的：
1, 1, 5
1, 5, 1
5, 1, 1
问有多少种不同的分法。

输入格式：
n, k（6 < n <= 200，2 <= k <= 6）

输出格式：
1 个整数，即不同的分法。
*/

#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int nums[N] = {0};

int DFSnumpar(int num, int start, int pos, int lot);

int main(){
    int n, k;
    cin >> n >> k;
    cout << DFSnumpar(n, 1, 0, k) <<endl;

}

int DFSnumpar(int num, int start, int pos, int lot){
    static int total = 0;
    int count = 0;
    
    if (pos == lot){
        if (total == num){
            count++;
        }
        return count;
    }

    for (int i = start; i <= num - lot + 1; i++){
        //可行性减枝，当该分支的最小可能值大于所求数时，退出，它一定不是最优解
        //这里把减枝放在递归前，减少时间开销
        if (total + start * (lot - pos) > num){
            return count;
        }
        
        total += i;
        count += DFSnumpar(num, i, pos + 1, lot);
        total -= i;
    }

    return count;
}
