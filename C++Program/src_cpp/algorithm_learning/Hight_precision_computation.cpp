#include<iostream>
#include <string>

using namespace std;

/*
这段高精度计算代码目前只能实现正整数的加减乘除的逻辑
还比较局限
*/

const int N = 1e7 + 10;

string num1, num2;
int N1[N] = {0}, N2[N] = {0}, endNum[N] = {0};
int len1, len2, lenE;

//此处store函数最好是用指针传入数组，用引用的话比较麻烦,需要写成如下形式：
//void s(int (&arr)[10]){}

void store(const string& num, int* arr, int& len){
    int pos = 0;
    len = num.size();
    //进行逆序存储，方便计算
    for (int i = len - 1; i >= 0; i--){
        *(arr + pos) = num[i] - '0';
        pos++;
    }
}

void addHuge(string& num1, string& num2, int* end, int& len){
    //先将两个字符串储存的大数转存到数组中并计算数字的位数
    store(num1, N1, len1);
    store(num2, N2, len2);

    int tol, rest;
    int max = num1.size() > num2.size() ? num1.size() : num2.size();

    //一位一位计算
    for (int i = 0; i < max + 1; i++){
        tol = N1[i] + N2[i] + rest;
        rest = tol / 10;
        tol %= 10;
        *(end + i) = tol;
        len++;
    }
    //对于最后一位，要检查是否有进位，防止len长度出错
    if (len > 1 && *(end + len - 1) == 0){
        len--;
    }
}

//此处默认num1 - num2
void subHuge(string& num1, string& num2, int* end, int& len){
    //先将两个字符串储存的大数转存到数组中并计算数字的位数
    store(num1, N1, len1);
    store(num2, N2, len2);

    int tol, rest;
    int max = num1.size() > num2.size() ? num1.size() : num2.size();

    //一位一位计算
    for (int i = 0; i < max + 1; i++){
        tol = N1[i] + N2[i] + rest;
        rest = tol / 10;
        tol %= 10;
        *(end + i) = tol;
        len++;
    }
    //对于最后一位，要检查是否有进位，防止len长度出错
    if (len > 1 && *(end + len - 1) == 0){
        len--;
    }
}

void showNum(int* N, int& len){
    if (len == 0){return;}

    for (int i = len - 1; i >= 0; i--){
        cout << N[i];
    }
    cout << endl;
}

int main(){
    cin >> num1 >> num2;

    store(num1, N1, len1);
    store(num2, N2, len2);
    cout << endl;
    showNum(N1, len1);
    showNum(N2, len2);
    
    cout << endl;
    addHuge(num1, num2, endNum, lenE);
    showNum(endNum, lenE);
}