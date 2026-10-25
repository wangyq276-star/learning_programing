/*
矩阵乘法

题目描述:
给定一个 m×n 的整数矩阵 A，以及一个 n×p 的整数矩阵 B。
请你计算矩阵乘积 C=A×B。
*/

#include<iostream>
#include<vector>

//这里借用了头文件里的print2D函数来输出打印矩阵
#include"print_tools.h"
using namespace std;

//建立三个二维数组来进行矩阵乘法计算
vector<vector<int>> A;
vector<vector<int>> B;
vector<vector<int>> C;

//对于函数的声明
int sum(const vector<vector<int>>& A, const vector<vector<int>>& B, int i, int j);
vector<vector<int>> multip(const vector<vector<int>>& A, const vector<vector<int>>& B);
void inputMatr(vector<vector<int>>& A);

int main(){

    int m, n, p;

    cout << "A_m " << endl;
    cin >> m;

    cout << "AB_n " << endl;
    cin >> n;

    cout << "B_p " << endl;
    cin >> p;
    //依据大小分配内存
    A.resize(m, vector<int>(n));
    B.resize(n, vector<int>(p));
    C.resize(m, vector<int>(p));

    cout << "A: " << endl;
    inputMatr(A);
    cout << endl;

    cout << "B: " << endl;
    inputMatr(B);

    cout << "A: ";
    print2D(A);
    cout << "B: ";
    print2D(B);


    C = multip(A, B);
    cout << "C: ";
    print2D(C);
}

//计算乘积矩阵的每一个元素
vector<vector<int>> multip(const vector<vector<int>>& A, const vector<vector<int>>& B){
    vector<vector<int>> res(0);
    if (A.empty() || B.empty()){
        cout << "Wrong" <<endl;
        return res;
    };
    int m = A.size(), p = B[0].size();
    res.resize(m, vector<int>(p));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            res[i][j] = sum(A, B, i, j);
        }
    }
    return res;
}

//把每个元素的计算方法单独拆出来，不然循环嵌套太多了
int sum(const vector<vector<int>>& A, const vector<vector<int>>& B, int i, int j){
    int n = A[0].size();
    int res = 0;
    for (int t = 0; t < n; t++){
        res += A[i][t] * B[t][j];
    }
    return res;
}

//用于输入矩阵的函数
void inputMatr(vector<vector<int>>& A){
    cout << "vector: " << endl;
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < A[0].size(); j++){
            cin >> A[i][j];
        }
    }
}

/*
测试用例：
A_m 10
AB_n 6
B_p 8
//A（10*6）B（6*8）
A: 
vector: 
0 1 2 3 4 5
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
5 6 7 8 9 10
6 7 8 9 10 11
7 8 9 10 11 12
8 9 10 11 12 13
9 10 11 12 13 14

B: 
vector: 
0 1 2 3 4 5 6 7
1 2 3 4 5 6 7 8
2 3 4 5 6 7 8 9
3 4 5 6 7 8 9 10
4 5 6 7 8 9 10 11
5 6 7 8 9 10 11 12

输出：
A: vector
[0,1,2,3,4,5]
[1,2,3,4,5,6]
[2,3,4,5,6,7]
[3,4,5,6,7,8]
[4,5,6,7,8,9]
[5,6,7,8,9,10]
[6,7,8,9,10,11]
[7,8,9,10,11,12]
[8,9,10,11,12,13]
[9,10,11,12,13,14]

B: vector
[0,1,2,3,4,5,6,7]
[1,2,3,4,5,6,7,8]
[2,3,4,5,6,7,8,9]
[3,4,5,6,7,8,9,10]
[4,5,6,7,8,9,10,11]
[5,6,7,8,9,10,11,12]

C: vector
[55,70,85,100,115,130,145,160]
[70,91,112,133,154,175,196,217]
[85,112,139,166,193,220,247,274]
[100,133,166,199,232,265,298,331]
[115,154,193,232,271,310,349,388]
[130,175,220,265,310,355,400,445]
[145,196,247,298,349,400,451,502]
[160,217,274,331,388,445,502,559]
[175,238,301,364,427,490,553,616]
[190,259,328,397,466,535,604,673]
*/