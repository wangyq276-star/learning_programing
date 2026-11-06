/*
用于获取一组数的全排列
以下以 1 ~ n 为例，得到他们的全排列

全排列的算法在许多题目中会用到，故这里总结一下实现思路：
1.建立一个 isPlaced[] 数组（或布尔类型数组）来实现对于元素是否已经被排列的信息存储
2.采用 DFS 完成遍历，并在每次遍历以前检查元素是否被放置
*/
#include<iostream>
#include <iomanip>

using namespace std;

const int N = 1e4 + 10;
int isPlaced[N] = {0};

void DFSfullPer(int rest, int size);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
     
    cin >> n;

    DFSfullPer(n, n);
}

void DFSfullPer(int rest, int size){
    static int permut[1000] = {0};

    if (rest == 0){
        for (int i = 0; i < size; i++){
            cout << setw(5) << permut[i];
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= size; i++){
        if (isPlaced[i]){
            continue;
        }

        isPlaced[i] = true;
        permut[size - rest] = i;
        DFSfullPer(rest - 1, size);
        //最虽然此处不写这个回溯好像也可以，因为新的值会把他覆盖掉，不过为了思路的完整性还是写一下
        permut[size - rest] = 0;
        isPlaced[i] = false;
    }
    return;
}