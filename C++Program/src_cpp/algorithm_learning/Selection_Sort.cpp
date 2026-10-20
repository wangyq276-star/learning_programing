#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;
// int L[N] = {5,3};
// int len = 2;

void sort(int * ls, int len){
    int temp;
    int index;
    

    //通过遍历，每次找最小的数
    for (int i = 0; i < len; i++){
        int min = ls[i];
        for (int j = len - 1; j > i; j--){
            if (ls[j] < min){
                min = ls[j];
                index = j;
            }
        }
        //不断与第一个未排序的元素交换位置
        temp = ls[i];
        ls[i] = min;
        ls[index] = temp;
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
    sort(L, len);
    show(L, len);
}