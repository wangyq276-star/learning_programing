/*
描述
给定一个数组，统计前k大的数并且把这k个数从大到小输出。

输入
第一行包含一个整数n，表示数组的大小。n < 100000。
第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。
每个整数的绝对值不超过100000000。
第三行包含一个整数k。k < n。

输出
从大到小输出前k大的数，每个数一行。
*/
#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N] = {0};
int n, k;

void Qsort(int* List, int left, int right){
  
    if (left >= right){
        return;
    }

    int l = left, m = left, r = right, p = List[left + ((right - left + 1) >> 1)];

    while (l <= r && m <= r){
    
        if (List[m] == p){
            m++;

        }else if (List[m] < p){
            swap(List[r--], List[m]);
        
        }else if (List[m] > p){
            swap(List[l++], List[m++]);
        }
    }

    Qsort(List, left, l - 1);
    Qsort(List, r + 1, right);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;

    Qsort(a, 0, n - 1);

    for (int i = 0; i < k; i++){
        cout << a[i] << endl;
    }
    
    return 0;
}