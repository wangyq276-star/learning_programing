/*
描述
小鲁虽然编程能力很一般，但是嘴皮子上不服输。
他很喜欢拿自己不懂的问题考小华。
刚学会冒泡排序的他，决定挑战一下小华的智商：
给定你一个长度为n的整数数列。
请你对这个数列按照从小到大进行排序。
并将排好序的数列按顺序输出。
小鲁刻意隐瞒了数据的规模，你觉得小华能够搞定吗?
偷偷告诉你：1≤n≤100000，所有整数均在1--10^9范围内
后记：小华使用快速排序秒过，小鲁惨败，因为他看不懂小华的代码......

输入
输入共两行，第一行包含整数 n。
第二行包含 n 个整数，表示整个数列。

输出
输出共一行，包含 n 个整数，表示排好序的数列。
*/
#include <iostream>
#include <time.h>
using namespace std;

const int N = 100000 + 10;
int num[N] = {0};
int n;

void sort(int l, int r){
    if (l >= r){
        return;
    }
    /*
        快速排序就是在分区间然后再对小区间继续排序
    */
    int flag = num[l + rand() % (r - l + 1)];
    int m = l, lt = l, gt = r;

    while(m <= r){
        if (num[m] == flag){
            m++;
        }else if (num[m] > flag){
            swap(num[m], num[r--]);
        }else{
            swap(num[m++], num[l++]);
        }
    }

    sort(lt, l - 1);
    sort(r + 1, gt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }

    srand(time(0));
    sort(0, n - 1);

    for (int i = 0; i < n; i++){
        cout << num[i] << ' ';
    }

    return 0;
}