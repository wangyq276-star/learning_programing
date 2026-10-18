#include <iostream>
using namespace std;

const int N = 1e6 +20;

// char nope[N];
// int len = 0;

// int point[N];
// int head = 0;

//测试用例

char nope[N] = {'a','b','c','d','f','g'};
int len = 6;
int point[N] = {2,4,1,5,3,6};

int head = 0;

//在链表里添加（插入）元素
void insert_front(int index, char input){
    if (index > 0 && index <= len + 1){
        nope[len] = input;
        int front = head;

        //通过for循环找到前驱节点
        for (int i = 0; i < index - 1; i++){
            front = point[front];
        }
        //把前驱节点的指针域赋给新节点，使其指向后节点
        point[len] = point[front];
        //改变前驱节点的指针域，使其指向新节点
        point[front] = len;
        len++;
    }else if (index == 0){
        nope[len] = input;
        //改变遍历时的首元素
        point[len] = head;
        head = len;
        len++;
    }else{
        cout << "index should be within 0 to " << len << endl; 
    }
}

//在链表中删去元素
void del(int index){
    if (index > 0 && index <= len + 1){
        int front = head;

        //通过for循环找到前驱节点
        for (int i = 0; i < index - 1; i++){
            front = point[front];
        }
        //直接跳过该节点，让前驱节点指向下一个节点
        point[front] = point[point[front]];
        len--;
    }else if (index == 0){
        head = point[head];
        len--;
    }
    
}

void show(){
    int temp = head;
    for(int i = 0; i < len; i++){
        cout << nope[temp] << " ";
        temp = point[temp];
    }
    cout << endl;
}

int main(){
    show();
    insert_front(2,'y');
    show();
    insert_front(0,'x');
    show();
    insert_front(6,'z');
    show();
    del(4);
    show();
    del(0);
    show();
}