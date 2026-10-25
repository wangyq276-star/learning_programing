#include<iostream>
#include"print_tools.h"
using namespace std;

const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;

// int L[N] = {5,3};
// int len = 2;

void Insert_sort(int * ls, int len);

int main(){
    show(L, len);
    Insert_sort(L, len);
    show(L, len);
}

void Insert_sort(int* List, int len){
    //遍历该数组的每一个元素（默认首元素有序）
    for (int i = 1; i < len; i++){
        //先把要插入的对象保存下来
        int key = List[i];
        //遍历后面已经有序的对象，如果比要插入的对象大，就把它往前移

        /*
        for (int j = i - 1; j >= 0; j--){
            if (List[j] < key){
                List[j + 1] = key;
                break;
            }
            List[j + 1] = List[j];
        }
        
        旧代码，会出现j小于0而退出，无法将key赋值给对应位置的问题
        */

        //以下为ai修改的代码
        int j = i - 1;
        while (j >= 0 && List[j] > key){
            List[j + 1] = List[j];
            j--;
        }
        List[j + 1] = key;
        
    }
} 
