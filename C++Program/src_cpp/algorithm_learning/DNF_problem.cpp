#include<iostream>
#include<ctime>
using namespace std;

const int N = 1e6 + 10;
int L[N] = {1,2,3, 1,1,2, 1,3,2, 3,2,1, 2,3,2, 
            2,1,3, 2,3,3, 1,2,1, 2,2,3, 1,2,1};
int len = 30;

//顺便练习一下泛型
template<typename T>
void myswap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

//这是为快排准备的函数

/*

int getRandom(int left, int right){
    srand(time(0));
    return rand() % (right - left + 1) + left;
}

*/

void sort(int left, int right){
    int l = left, m = left, r = right;
    //int p = getRandom(left, right);
    int p = 2;
    while (l <= r && m <= r){
        if (L[m] == p){
            m++;
        }else if (L[m] > p){
            myswap(L[r], L[m]);
            r--;
        }else if (L[m] < p){
            myswap(L[l], L[m]);
            l++;
            m++;
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
    sort(0, len - 1);
    show(L, len);
}