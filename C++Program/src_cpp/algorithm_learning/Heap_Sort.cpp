/*
堆排序的思路：
首先每一个父节点与其左右两个子节点的数组下标关系是：
father = i;
left_son = 2i + 1;
right_son = 2i + 2;
（这是建立在该堆是一个完全二叉树的基础上）

而排序开始的点是第一个非叶子节点，其下标为：(n - 1) / 2
（n 是数组的长度）
*/
#include<iostream>
#include"print_tools.h"

using namespace std;

const int N = 1e6 + 10;
int L[N] = {65,48,15, 8,60,44, 81,49,45, 37,35,69, 7,56,91, 
            83,71,98, 70,32,24, 38,85,59, 21,9,24, 6,84,54};
int len = 30;

void heapify(int* List, int len, int father);
void Heap_sort(int* List, int len);

int main(){

    show(L, len);
    Heap_sort(L, len);
    show(L, len);
}

void Heap_sort(int* List, int len){

    //从倒数第一个非叶子节点开始建立堆
    //其处理结果就是让这个树满足大根堆的规则
    for (int i = (len - 1) >> 1; i >= 0; i--){
        heapify(List, len, i);
    }

    //这里采用倒序遍历是因为此时 i 可以用于代表剩余未排序元素的个数，也可以代表最后一个元素的下标
    for (int i = len - 1; i >= 0; i--){

        //把已经得到的余下堆的最大值放到数组的最后
        swap(List[0], List[i]);

        //然后继续整理余下的堆
        //因为经历过建堆的过程，所以第二大的数一定在根节点的两个子节点中产生
        heapify(List, i, 0);
    }
}

void heapify(int* List, int len, int father){

    //先表示出父节点和子节点，默认假设父节点最大
    int largest = father;
    int left = 2 * father + 1;
    int right = 2 * father + 2;

    //开始比较父子结点的大小，并将指针进行交换
    if (left < len && List[left] > List[largest]){
        left = father;
        largest = 2 * father + 1;
    }
    if (right < len && List[right] > List[largest]){
        right = father;
        largest = 2 * father + 2;
    }

    //如果最大的节点不是父节点，那么就要进行交换，此时要对经过交换的节点重新排序
    if (largest != father){
        swap(List[largest], List[father]);
        heapify(List, len, largest);
    }else{
        return;
    }
}
