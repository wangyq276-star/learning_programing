#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;

int temp[N] = {};

void sort(int left, int right){
    if (left >= right){
        return;
    }

    //使用位运算符进行除以二的操作，更快速
    int mid = (right + left) >> 1;

    //采用递归完成排序，其结果默认有序
    sort(left, mid);
    sort(mid + 1, right);

    //借助辅助数组完成有序数组的合并（难点）
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right){
        if (L[i] < L[j]){
            temp[k++] = L[i++];
        }else{
            temp[k++] = L[j++];
        }
    }
    while (i <= mid){
        temp[k++] = L[i++];
    }
    while (j <= right){
        temp[k++] = L[j++];
    }

    for (int t = 0; t < k; t++){
        L[t] = temp[t];
    }
} 

void show(int * ls, int len){
    for (int i = 0; i < len; i++){
        cout << ls[i] << " ";
    }
    cout << endl;
}

int main(){
    show(L, len);
    sort(0, len - 1);
    show(L, len);
}