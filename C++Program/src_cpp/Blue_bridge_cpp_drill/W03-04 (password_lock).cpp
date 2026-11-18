/*
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30）
按钮有凹/凸两种状态，用手按按钮会改变其状态。
然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。
当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
当前密码锁状态已知，需要解决的问题是：
    你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态。
其中0代表凹，1代表凸。

输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
*/
#include <cstring>
#include <iostream>
using namespace std;

const int N = 40;
bool lock[N] = {0}, pass[N] = {0};
int len;

/* 用于改变按钮状态 */
void change(bool *List, int len, int idx) {
    if (idx < 0 && idx >= len) {
        return;
    }
    List[idx] = !List[idx];
    if (idx - 1 >= 0) {
        List[idx - 1] = !List[idx - 1];
    }
    if (idx + 1 < len) {
        List[idx + 1] = !List[idx + 1];
    }
    return;
}

void countTimes() {
    long long total1 = 0, total2 = 0;
    bool copy[N] = {0};

    /*
        这里要分两类讨论状态，我之前没有想全：
        1.第一个按钮不按
        2.第一个按钮按下
        之后下一步使用贪心策略：
        如果第 i 号按钮与密码状态相同则跳过，不同就按下 i + 1 号按钮
        最后比较两个方案中所需最小的那个
    */

    // 情况 1
    memcpy(copy, lock, sizeof(lock));
    change(copy, len, 0);
    total1++;
    for (int i = 0; i < len - 1; i++) {
        if (copy[i] ^ pass[i]) {
            change(copy, len, i + 1);
            total1++;
        }
    }
    if (copy[len - 1] ^ pass[len - 1]) {
        /*
            如果最后一个按钮状态不符合
            说明这种情况不行
            一般竞赛中会使用 0x3f3f3f3f 代表无穷大
            （原因在于它比较大，但是和另一个 0x3f3f3f3f 相加又不会导致溢出）
            这样待会与 total2 比较时不会出现差错
        */
        total1 = 0x3f3f3f3f3f3f3f3f;
    }

    // 情况 2
    memcpy(copy, lock, sizeof(lock));
    for (int i = 0; i < len - 1; i++) {
        if (copy[i] ^ pass[i]) {
            change(copy, len, i + 1);
            total2++;
        }
    }

    if (copy[len - 1] ^ pass[len - 1]) {
        total2 = 0x3f3f3f3f3f3f3f3f;
    }

    // 找到最小值
    long long count = min(total1, total2);
    if (count < 0x3f3f3f3f3f3f3f3f) {
        cout << count << endl;
    } else {
        cout << "impossible" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string cur, dst;
    cin >> cur >> dst;
    len = cur.size();
    for (int i = 0; i < len; i++) {
        lock[i] = cur[i] - '0';
        pass[i] = dst[i] - '0';
    }

    countTimes();

    return 0;
}