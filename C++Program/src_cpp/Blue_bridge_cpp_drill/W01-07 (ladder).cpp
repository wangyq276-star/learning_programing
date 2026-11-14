/*
描述
经过激烈的战斗，林克过关斩将终于抵达初阶递归之试炼的最后一关。
在他面前有一座天梯，天梯的顶端就是传说中的递归试炼通过证了。
林克每步可以跨一级台阶或者跨二级台阶。他必须尝试所有的走法才能得到递归试炼通过证。
如果天梯的台阶数是N，请问他总共需要尝试多少种走法？

输入
输入天梯的台阶数N。
(1<=N<=30)

输出
总共有几种走法
*/
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
//创建“备忘录”
int a[N] = {1, 1};

int method(int n){
    if (n == 1)return 1;

    /* 即使这里可以使用递归的方法实现，
        但是使用数组来存储之前已经计算好的数来避免重复计算时间开销来的更小
        此方法再求斐波那契数列的模板题中已有使用 */
    for (int i = 2; i < n + 1; i++){
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << method(n) << endl;
}

