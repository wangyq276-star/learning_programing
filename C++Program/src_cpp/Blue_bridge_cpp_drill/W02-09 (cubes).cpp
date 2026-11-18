/*
描述
形如a^3= b^3+ c^3+ d^3的等式被称为完美立方等式。
例如12^3= 6^3+ 8^3+ 10^3。
编写一个程序，对任给的正整数N (N≤100)，
寻找所有的四元组(a, b, c, d)，使得a^3= b^3+ c^3+ d^3，
其中a,b,c,d 大于 1, 小于等于N，且b<=c<=d。

输入
一个正整数N (N≤100)。

输出
每行输出一个完美立方。输出格式为：
Cube = a, Triple = (b,c,d)
其中a,b,c,d所在位置分别用实际求出四元组值代入。
请按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则b值小的优先输出、仍相同则c值小的优先输出、再相同则d值小的先输出。
*/
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int N = 110;
int cube[N] = {0};

typedef struct group {
    int a, b, c, d;
    group(int A, int B, int C, int D) {
        this->a = A;
        this->b = B;
        this->c = C;
        this->d = D;
    }
} Gp;

vector<Gp> cubes;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i < 100; i++) {
        cube[i] = i * i * i;
    }

    for (int a = 6; a < n + 1; a++) {
        for (int d = 2; d <= a; d++) {
            for (int c = 2; c <= d; c++) {
                for (int b = 2; b <= c; b++) {
                    if (cube[a] == cube[b] + cube[c] + cube[d]) {
                        Gp g(a, b, c, d);
                        cubes.push_back(g);
                    }
                }
            }
        }
    }

    sort(cubes.begin(), cubes.end(), [](const Gp &A, const Gp &B) {
        if (A.a != B.a)
            return A.a < B.a;
        if (A.b != B.b)
            return A.b < B.b;
        if (A.c != B.c)
            return A.c < B.c;
        return A.d < B.d;
    });

    for (auto i : cubes) {
        printf("Cube = %d, Triple = (%d,%d,%d)\n", i.a, i.b, i.c, i.d);
    }
    return 0;
}