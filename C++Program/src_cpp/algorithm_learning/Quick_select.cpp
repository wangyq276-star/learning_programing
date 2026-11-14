/*
洛谷（https://www.luogu.com.cn/problem/P1923）

题目描述：
输入 n 个数字 a_i，输出这些数字中第 k 小的数。最小的数是第 0 小。
请尽量不要使用 nth_element 来写本题，因为本题的重点在于练习分治算法。

输入格式：
第一行有两个整数，分别表示 n 和 k。
第二行有 n 个整数，第 i 个数表示 a_i。

输出格式：
一个整数，表示第 k 小的数。
*/
#include <iostream>
using namespace std;

const int N = 1e7 + 10;
int a[N] = {0};
int n, k;

int findK(int left, int right, int rankK){
    //递归出口
    if (left == right){
        return a[left];
    }

    //当然随机选取 flag 的值更好，就像快排那样，这里为了简便选取中点的值
    int flag = a[left + ((right - left + 1) >> 1)];
    
    int mid = left, l = left, r = right;

    /* 
        首先，要把数列分为三个区间：
        1.小于 flag 
        2.等于 flag 
        3.大于 flag
    */
    while(mid <= r){
        if (a[mid] == flag){
            mid++;
        }else if (a[mid] > flag){
            swap(a[mid], a[r--]);
        }else{
            swap(a[mid++], a[l++]);
        }
    }

    /*
        接下来，判断第 k 小的数是否落在等于 flag 的重复元素区间内
        1.等于，直接输出flag
        2.大于，在右边继续寻找
        3.小于，在左边继续寻找
        需要注意的是此处 rankK 代表了全局下标
    */
    if (rankK >= l && rankK < mid){
        return flag;
    }else if(rankK < l){
        return findK(left, l - 1, rankK);
    }else{
        return findK(mid, right, rankK);
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    //此处题目说存在第 0 小的数，所以 k 不用减一
    cout << findK(0, n - 1, k) << endl;

    return 0;
}