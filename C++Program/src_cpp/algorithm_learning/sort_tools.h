/*
以下集合了所有我写的排序算法，便于今后调用
*/
#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <cstdlib>

// ==================== 冒泡排序 ====================
inline void Bubble_sort(int* List, int len){
    if (len <= 0){
        return;
    }
    int temp;
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - 1 - i; j++){
            if (List[j] > List[j+1]){
                temp = List[j+1];
                List[j+1] = List[j];
                List[j] = temp;
            }
        }
    }
} 

// ==================== 选择排序 ====================
inline void Selection_sort(int* List, int len) {
    if (len <= 0){
        return;
    }
    for (int i = 0; i < len; i++) {
        int min = List[i];
        int index = i;              

        for (int j = len - 1; j > i; j--) {
            if (List[j] < min) {
                min = List[j];
                index = j;
            }
        }

        int temp = List[i];
        List[i] = min;
        List[index] = temp;
    }
}

// ==================== 插入排序 ====================
inline void Insert_sort(int* List, int len) {
    if (len <= 0){
        return;
    }
    for (int i = 1; i < len; i++) {
        int key = List[i];
        int j = i - 1;
        while (j >= 0 && List[j] > key) {
            List[j + 1] = List[j];
            j--;
        }
        List[j + 1] = key;
    }
}

// ==================== 归并排序 ====================
inline void Merge_sort(int* List, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + ((right - left) >> 1);

    Merge_sort(List, left, mid);
    Merge_sort(List, mid + 1, right);

    std::vector<int> temp(right - left + 1);

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (List[i] <= List[j]) {
            temp[k++] = List[i++];
        } else {
            temp[k++] = List[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = List[i++];
    }
    while (j <= right) {
        temp[k++] = List[j++];
    }

    for (int t = 0; t < k; t++) {
        List[left + t] = temp[t];
    }
}

// ==================== 快速排序 ====================
template<typename T>
inline void myswap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

inline int getRandom(int left, int right) {
    return rand() % (right - left + 1) + left;
}

inline void Quick_sort(int* List, int left, int right) {
    if (left >= right) {
        return;
    }
    int l = left, m = left, r = right;
    int p = List[getRandom(left, right)];

    while (l <= r && m <= r) {
        if (List[m] == p) {
            m++;
        } else if (List[m] > p) {
            myswap(List[r--], List[m]);
        } else {
            myswap(List[l++], List[m++]);
        }
    }

    Quick_sort(List, left, l - 1);
    Quick_sort(List, r + 1, right);
}

#endif