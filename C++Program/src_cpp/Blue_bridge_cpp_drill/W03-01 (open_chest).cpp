/*
描述
林克面前有3个铁箱和一个宝箱。
三个铁箱里面有一个是“光之剑”，其余的两个箱子里面是小匕首。
林克需要用铁锤砸碎箱子才能得到箱子里面的武器。
然而林克身上带着的铁锤已经快坏了，只能砸碎一个铁箱。
为了得到“光之剑”，林克只有一次砸箱的机会。
好消息是宝箱里面有一个“电子透视镜”，
当林克戴上电子透视镜后，当他选中某一个箱子后，
电子透视镜就会提示他，其余的两个箱子中哪一个是小匕首。
这样，林克就可以赢得一次更换选择铁箱的机会。
原来林克需要三选一，这样只需要二选一。
请问：林克使用应不应该使用电子透视镜，
    使用这个装置是否能够增加林克得到光之剑的机会呢？
请对开铁箱问题进行 10 000 000 次模拟操作，
输出更换选择后得到光之剑的概率，结果保留6位小数。

无输入

输出
输出一个6位小数
本题采用Special Judge，只要正确模拟，误差不会影响判题。
*/

/*
    其实如果你数学比较好，那么答案就是 2/3
    只需要打印出 (double)2/3 的前 6 位小数就好
    但是这就没什么乐趣了
    #include <stdio.h>
    int main(){
        printf("%.6f",(double)2/3);
        return 0;
    }

    下面采用蒙特卡洛方法的模拟
*/
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;

const int N = 1e7 + 10;
int res[N] = {0};
int box[3] = {0};

int main() {
    srand(time(0));

    long long n = 1e7;
    while (n--) {
        // int i = rand() % 3;
        int choice = rand() % 3;
        box[1] = 1;
        if (box[choice]) {
            res[n] = 0;
        } else {
            res[n] = 1;
        }
    }

    double count = 0;
    for (long i = 0; i < 1e7; i++) {
        if (res[i]) {
            count++;
        }
    }
    cout << count / 1e7 << endl;

    return 0;
}