/*
描述
打表法是寻找回忆不可或缺的重要方法
如果配合上lowbit，那么更难的问题也能迎刃而解。
请运用打表法和lowbit算法解决如下问题：
给定一个16位的十进制数，请把该数转换为二进制数来看待。
请找到该数看为二进制后，其最低位的1出现的位置。
也就是这个数最低位的1是二进制中的第几位呢？

输入
以1开头的二进制数的十进制表示B.

输出
输出K，表示B中的1在第K位（K=0,1,2....15)
9的最低位的1出现在位置0.
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 32; i++){
        if ((n >> i) & 0b1){
            cout << i << endl;
            break;
        }
    }

    return 0;
}