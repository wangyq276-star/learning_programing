/*
洛谷（https://www.luogu.com.cn/problem/P1886）

题目描述：
有一个长为 n 的序列 a，以及一个大小为 k 的窗口。
现在这个窗口从左边开始向右滑动，每次滑动一个单位，
求出每次滑动后窗口中的最小值和最大值。
例如，对于序列 [1, 3, -1, -3, 5, 3, 6, 7] 以及 k = 3，有如下过程：

窗口位置              最小值  最大值
[1 3 -1] -3 5 3 6 7    -1      3
1 [3 -1 -3] 5 3 6 7    -3      3
1 3 [-1 -3 5] 3 6 7    -3      5
1 3 -1 [-3 5 3] 6 7    -3      5
1 3 -1 -3 [5 3 6] 7     3      6
1 3 -1 -3 5 [3 6 7]     3      7

输入格式：
输入一共有两行，第一行有两个正整数 n, k；第二行有 n 个整数，表示序列 a。

输出格式：
输出共两行，第一行为每次窗口滑动的最小值；第二行为每次窗口滑动的最大值。
*/
#include<iostream>
#include<deque>

using namespace std;
 
const int N = 1e7 + 10;

int a[N] = {0};
int n, k;

void findMax(int* nums, int len, int window);
void findMin(int* nums, int len, int window);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    findMin(a, n, k);
    findMax(a, n, k);
}
/* 找到滑动窗口内元素的最大值 */
void findMax(int* nums, int len, int window){
    deque<int> q;
    int index[len + 5] = {0};

    for (int i = 0; i < len; i++){
        //维护一个单调递减的队列，每次找队首元素，就是最大值
        //注意限制条件有两个：递减所以小于它的要扔掉 ； 队列里存的下标不能超出滑动窗口对应的下标范围
        while (!q.empty() && nums[q.back()] < nums[i]){
            q.pop_back();
        }
        while (!q.empty() && q.front() <= i - window){
            q.pop_front();
        }
        q.push_back(i);
        //由于前 k - 1 个元素时滑动窗口还未完全进入区间，所以不执行操作
        if (i < window - 1){
            continue;
        }
        index[i] = q.front();
    }

    for (int i = window - 1; i < len; i++){
        cout << nums[index[i]] << ' ';
    }
    cout << endl;
}

/* 找到滑动窗口内元素的最小值 */
void findMin(int* nums, int len, int window){
    deque<int> q;
    int index[len + 5] = {0};

    for (int i = 0; i < len; i++){
        while (!q.empty() && nums[q.back()] > nums[i]){
            q.pop_back();
        }
        while (!q.empty() && q.front() <= i - window){
            q.pop_front();
        }
        q.push_back(i);
        //由于前 k - 1 个元素时滑动窗口还未完全进入区间，所以不执行操作
        if (i < window - 1){
            continue;
        }
        index[i] = q.front();
    }

    for (int i = window - 1; i < len; i++){
        cout << nums[index[i]] << ' ';
    }
    cout << endl;
}