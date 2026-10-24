/*
洛谷算法题（https://www.luogu.com.cn/problem/P10449）

题目描述
25 盏灯排成一个 5×5 的方形。
每一个灯都有一个开关，游戏者可以改变它的状态。
每一步，游戏者可以改变某一个灯的状态。
游戏者改变一个灯的状态会产生连锁反应：和这个灯上下左右相邻的灯也要相应地改变其状态。
我们用数字 1 表示一盏开着的灯，用数字 0 表示关着的灯。

下面这种状态
10111
01101
10111
10000
11011

在改变了最左上角的灯的状态后将变成：
01111
11101
10111
10000                       
11011

再改变它正中间的灯后状态将变成:    
01111
11001
11001
10100
11011


给定一些游戏的初始状态，编写程序判断游戏者是否可能在 6 步以内使所有的灯都变亮。
*/

#include<iostream>
#include"print_tools.h"

using namespace std;

void changeLit(int i, int j, int (&L)[5][5]);
bool turnSixTimes(int (&L)[5][5]);

//用二维数组保存所有灯的状态
int L[5][5] ={{0}};

int main(){

    /*
    此版本代码只允许输入为一行的情况，不然会读入换行符导致数据出错
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            L[i][j] = getchar() - 48;
        }
    }
    */

    //更新为使用字符串读入每一行数据如下
    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;                   
        for (int j = 0; j < 5; j++)
            L[i][j] = s[j] - '0';     
    }

    //测试用代码
    //print2D(L);
    // changeLit(0, 1, L);
    // print2D(L);
    turnSixTimes(L);
}

//编写一个函数用于更新灯的状态
void changeLit(int i, int j, int (&L)[5][5]){
    //如果输入的i，j不合法就直接退出
    if (0 > i || i > 4 || 0 > j || j > 4){
        return;
    }
    //通过上下左右和自身这四个向量来得到需要改变的值
    int di[] = {0, 1, 0, -1, 0};
    int dj[] = {0, 0, 1, 0, -1};
    for (int t = 0; t < 5; t++){
        if (0 > i + di[t] || i + di[t] > 4 || 0 > j + dj[t] || j + dj[t] > 4){
            continue;
        }
        L[i + di[t]][j + dj[t]] = L[i + di[t]][j + dj[t]] == 0 ? 1 : 0;
    }

}

//编写函数，用于计算至少需要开关的次数
bool turnSixTimes(int (&L)[5][5]){

    ///记录需要按的次数
    int total;

    //第二次循环时记录需要按的地方
    int change[5] = {0};

    //保存原始数组用于枚举
    int copy[5][5];

    //用布尔值来标记有没有找到
    bool flag = 0;

    //第一行按按钮总共2的5次方种情况
    for (int i = 0; i < (1 << 5); i++){
        //先重置数组和计数器
        memcpy(copy, L, sizeof(int) * 25);
        total = 0;

        //然后对于每一个二进制数字（每一种情况）进行对应改变
        for (int j = 0; j < 5; j++){
            //这里，通过>>运算符和逐位与&来获取i的二进制的第j位是0还是1
            //此时由于1的二进制是000...0001，从而达到了只取第j位的目的，1作为掩码
            if ((i >> j) & 1){
                changeLit(0, j, copy);
                total++;
            }
        }

        //然后逐行检查需要按的每一行按钮(处理0 ~ 3行然后检查第四行是否符合条件)
        for (int m = 0; m < 4; m++){

            //先重置change
            for (int c = 0; c < 5; c++){
                change[c] = 0;
            }

            //检查是否为0，是否需要按按钮
            for (int n = 0; n < 5; n++){
                if (copy[m][n] == 0){
                    total++;
                    change[n] = 1;
                }
            }

            //对需要按按钮的地方执行change操作
            for (int c = 0; c < 5; c++){
                if (change[c] == 1){
                    changeLit(m + 1, c, copy);
                }
            }
        }

        //如果有一次少于六步，就检验最后一行是否为0
        if (total <= 6){
            flag = 1;
            for (int j = 0; j < 5; ++j) {
                if (copy[4][j] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (total <= 6 && flag){
                break; 
            }
        }
    }
    //此处输出是不必要的，只是检验一下函数是否正常工作
    if (flag){
        std::cout << "TES";
    }else{
        std::cout << "NO";
    }
    
    return flag;
}