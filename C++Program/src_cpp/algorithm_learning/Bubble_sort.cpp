#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {1,5,3, 7,7,14, 18,11,10 ,25,28,23 ,20,37,34 ,39};
int len = 15;
// int L[N] = {5,3};
// int len = 2;

void sort(int * ls, int len){
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