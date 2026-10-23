#include<iostream>
#include<ctime>
#include"tools.h"
using namespace std;

const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;

//顺便练习一下泛型
template<typename T>
void myswap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

//使用取余法获取某一区间内的随机数
int getRandom(int left, int right){
    return rand() % (right - left + 1) + left;
}

void Quick_sort(int left, int right){
    //保证区间长度非负
    if (left >= right){
        return;
    }

    int l = left, m = left, r = right, p = L[getRandom(left, right)];

    while (l <= r && m <= r){
        //如果等于基准值，不做改变
        if (L[m] == p){
            m++;
        //如果大于，往前面放
        }else if (L[m] > p){
            myswap(L[r--], L[m]);
        //小于，往后面放
        }else if (L[m] < p){
            myswap(L[l++], L[m++]);
        }
    }

    /*
    
    使用递归解决剩下的区块
    第一次我把区间写错了，导致有元素被重复处理
    sort(left, l);
    sort(r, right);

    */
    //正确代码如下

    Quick_sort(left, l - 1);
    Quick_sort(r + 1, right);
}

int main(){
    srand(time(0));

    show(L, len);
    Quick_sort(0, len - 1);
    show(L, len);
}