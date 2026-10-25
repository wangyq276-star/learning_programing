#include<iostream>
#include"print_tools.h"
using namespace std;

//测试用例
const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;

void Merge_sort(int* List, int left, int right);

int main(){
    show(L, len);
    Merge_sort(L, 0, len - 1);
    show(L, len);
}

//加入List，提高代码的解耦能力
void Merge_sort(int* List, int left, int right){
    if (left >= right){
        return;
    }

    //归并排序一定要借用第二个数组，无法仅通过自身完成排序
    int temp[right - left + 5] = {};

    //使用位运算符进行除以二的操作，更快速
    int mid = (right + left) >> 1;

    //采用递归完成排序，其结果默认有序
    Merge_sort(List, left, mid);
    Merge_sort(List, mid + 1, right);

    //借助辅助数组完成有序数组的合并（难点）
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right){
        if (List[i] < List[j]){
            temp[k++] = List[i++];
        }else{
            temp[k++] = List[j++];
        }
    }
    while (i <= mid){
        temp[k++] = List[i++];
    }
    while (j <= right){
        temp[k++] = List[j++];
    }

    for (int t = 0; t < k; t++){
        List[t + left] = temp[t];
    }
} 
