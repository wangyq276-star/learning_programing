#include<iostream>
#include"print_tools.h"
using namespace std;

const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;
// int L[N] = {5,3};
// int len = 2;

void Bubble_sort(int * ls, int len){
    int temp;
    
    //不断与前一个元素比较，并作交换，每一轮选出第n大的数
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - 1 - i; j++){
            if (ls[j] > ls[j+1]){
                temp = ls[j+1];
                ls[j+1] = ls[j];
                ls[j] = temp;
            }
        }
    }
} 

int main(){
    show(L, len);
    Bubble_sort(L, len);
    show(L, len);
}