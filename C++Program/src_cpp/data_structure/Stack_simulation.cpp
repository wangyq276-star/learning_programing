#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int stack[N] = {1,4,6,2,7,9};
int top = 5;

void push(int input){
    stack[top++] = input;
}

int pop(){
    return stack[top--];
}

void show(){
    cout << "bottom" << ' ';
    for (int i = 0; i < top + 1; i++){
        cout << stack[i] << ' ';
    }
    cout << "top" << endl;
}

int main(){
    show();
}