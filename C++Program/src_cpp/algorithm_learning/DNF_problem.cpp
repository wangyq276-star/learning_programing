/*
荷兰国旗问题（Dutch National Flag Problem），又称三色旗问题或三路划分问题
定义：
给定一个包含三类元素的数组（通常记为 0、1、2，或红、白、蓝三种颜色）
要求在线性时间内、使用常数级额外空间重新排列数组
使所有同类元素相邻，并按照指定顺序排列。
形式上，可描述为：
对数组进行原地划分，使其满足：
所有小于某中间值的元素在前，
等于中间值的元素居中，
大于中间值的元素在后；
典型情形是排序只含 0、1、2 的数组。
*/
#include<iostream>
#include<ctime>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {1,2,3, 1,1,2, 1,3,2, 3,2,1, 2,3,2, 
            2,1,3, 2,3,3, 1,2,1, 2,2,3, 1,2,1};
int len = 30;

//顺便练习一下泛型
template<typename T>
void myswap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

//这是为快排准备的函数

/*

int getRandom(int left, int right){
    srand(time(0));
    return rand() % (right - left + 1) + left;
}

*/

void sort(int left, int right){
    int l = left, m = left, r = right;
    //int p = getRandom(left, right);
    int p = 2;
    while (l <= r && m <= r){
        if (L[m] == p){
            m++;
        }else if (L[m] > p){
            myswap(L[r], L[m]);
            r--;
        }else if (L[m] < p){
            myswap(L[l], L[m]);
            l++;
            m++;
        }
    }
}

void show(const int * ls, int len){
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