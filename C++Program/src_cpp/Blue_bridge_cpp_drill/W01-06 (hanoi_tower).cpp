/*
描述
有三根杆子A，B，C。A杆上有N个(N>1)穿孔圆盘，盘的尺寸由下到上依次变小。
要求按下列规则将所有圆盘移至C杆： 每次只能移动一个圆盘； 大盘不能叠在小盘上面。 
提示：可将圆盘临时置于B杆，也可将从A杆移出的圆盘重新移回A杆，但都必须遵循上述两条规则。
问：如何移？最少要移动多少次？

解法
解法的基本思想是递归。
假设有A、B、C三个塔，A塔有N块盘
目标是把这些盘全部移到C塔。
那么先把A塔顶部的N-1块盘移动到B塔，再把A塔剩下的大盘移到C，最后把B塔的N-1块盘移到C。 
每次移动多于一块盘时，则再次使用上述算法来移动。

输入
盘子个数n(1<=n<=20)

输出
输出移动的步骤，每行一步，如从A座移动到C座，输出"A->C"。
*/
#include<iostream>
using namespace std;

void times(char a, char b, char c, int n);

int main(){
    int n;
    cin >> n;
    times('A', 'B', 'C', n);
}

void times(char src, char mid, char dist, int n){
    if (n == 0) return;

    //运用递归解决汉诺塔
    times(src, dist, mid, n - 1);
    cout << src << "->" << dist << endl;
    times(mid, src, dist, n - 1);
    return;
}