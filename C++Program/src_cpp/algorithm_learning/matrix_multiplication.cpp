/*
矩阵乘法

题目描述:
给定一个 m×n 的整数矩阵 A，以及一个 n×p 的整数矩阵 B。
请你计算矩阵乘积 C=A×B。
*/

#include<iostream>
#include<vector>

//这里借用了subset.cpp里的print2D函数来输出打印矩阵
#include"subset.cpp"
using namespace std;

vector<vector<int>> A;
vector<vector<int>> B;
vector<vector<int>> C;

//对于函数的声明
int sum(const vector<vector<int>>& A, const vector<vector<int>>& B, int i, int j);
vector<vector<int>> cal(const vector<vector<int>>& A, const vector<vector<int>>& B);
void inputMatr(vector<vector<int>>& A);

int main(){

    int m, n, p;

    cout << "A_m" << endl;
    cin >> m;

    cout << "AB_n" << endl;
    cin >> n;

    cout << "B_p" << endl;
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


    C = cal(A, B);
    cout << "C: ";
    print2D(C);
}

//计算乘积矩阵的每一个元素
vector<vector<int>> cal(const vector<vector<int>>& A, const vector<vector<int>>& B){
    if (A.empty() || B.empty()){
        cout << "Wrong" <<endl;
        return;
    };
    int m = A.size(), p = B[0].size();
    vector<vector<int>> res(m, vector<int>(p));
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