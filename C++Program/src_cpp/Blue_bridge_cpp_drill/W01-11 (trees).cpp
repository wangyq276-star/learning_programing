/*
描述
某校大门外长度为 L 的马路上有一排树，每两棵相邻的树之间的间隔都是 1 米。
我们可以把马路看成一个数轴，马路的一端在数轴 0 的位置，另一端在 L 的位置；
数轴上的每个整数点，即 0,1,2,……,L，都有一棵树。
由于马路上有一些区域要用来建地铁。
这些区域用它们在数轴上的起始点和终止点表示。
已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。
现在要把这些区域中的树（包括区域端点处的树）移走。
你的任务是计算将这些树移走后，马路上还有多少棵树。

输入
输入文件的第一行有两个整数 L 和 M，L 代表马路的长度，M 代表区域的数目，L 和 M 之间用一个空格隔开。
接下来的 M 行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

输出
输出文件包含一行，这一行只包含一个整数，表示马路上剩余的树的数目。

数据范围：
1 ≤ L ≤ 10000，
1 ≤ M ≤ 100
*/
#include <iostream>
using namespace std;

int l, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> l >> m;
    int a[l + 1] = {0};
    while (m--){
        int left, right;
        cin >> left >> right;

        for (int i = left; i <= right; i++){
            if (a[i]){
                continue;
            }
            a[i]++;
        }
    }
    
    int amount = l + 1;
    for (int i = 0; i < l + 1; i++){
        if (a[i]){
            amount--;
        }
    }

    cout << amount << endl;
    return 0;
}