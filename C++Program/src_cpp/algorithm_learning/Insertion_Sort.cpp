#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {1,5,3, 7,7,14, 18,11,10 ,25,28,23 ,20,37,34 ,39};
int len = 16;

// int L[N] = {5,3};
// int len = 2;

void sort(int * ls, int len){
    //遍历该数组的每一个元素（默认首元素有序）
    for (int i = 1; i < len; i++){
        //先把要插入的对象保存下来
        int key = ls[i];
        //遍历后面已经有序的对象，如果比要插入的对象大，就把它往前移

        /*
        for (int j = i - 1; j >= 0; j--){
            if (ls[j] < key){
                ls[j + 1] = key;
                break;
            }
            ls[j + 1] = ls[j];
        }
        
        旧代码，会出现j小于0而退出，无法将key赋值给对应位置的问题
        */

        //以下为ai修改的代码
        int j = i - 1;
        while (j >= 0 && ls[j] > key){
            ls[j + 1] = ls[j];
            j--;
        }
        ls[j + 1] = key;
        
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
    sort(L, len);
    show(L, len);
}