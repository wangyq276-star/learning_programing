/*
描述
为了寻找失去的回忆碎片，林克必须预备足够的料理。能够快速突破数独试炼，熟练运用lowbit，才能把难题转换为美味佳肴。
请用lowbit解决如下问题：
输入一个32位整数，输出该数二进制表示中1的个数。
注意：
负数在计算机中用其绝对值的补码来表示。

输入：9
输出：2
解释：9的二进制表示是1001，一共有2个1。

输入：-2
输出：31
解释：-2在计算机里会被表示成 1111 1111 1111 1111 1111 1111 1111 1110，
一共有31个1。
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int count = 0;

    for (int i = 0; i < 8 * 4; i++){
        if ((n >> i) & 0b1){
            count++;
        }
    }

    cout <<  count << endl;

    return 0;
}