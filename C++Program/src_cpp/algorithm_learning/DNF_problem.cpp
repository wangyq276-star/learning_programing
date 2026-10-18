#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {1,5,3, 7,7,14, 18,11,10 ,25,28,23 ,20,37,34 ,39};
int len = 15;

//顺便练习一下泛型
template<typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

void sort(int * ls, int len){
    int low = 0, mid = 0, right = len - 1;
    for (int i = 0; i < len; i++){
        //还没做完，明天再说
    }
}