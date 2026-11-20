/*
描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
输入包含多组测试数据。
每组数据占两行，分别表示两个日期，形式为YYYYMMDD。

输出
每组数据输出一行，即日期差值。
数据范围
年份范围 [1, 9999]。
保证输入日期合法。
测试数据的组数不超过 100。
*/
#include <iostream>

using namespace std;

int time1[3], time2[3];

bool isRUN(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 对输入时间进行处理，获取年月日
    int T, cur = 0;
    cin >> T;
    for (int i = 10000; i >= 1; i /= 100) {
        time1[cur++] = T / i;
        T %= i;
    }
    cur = 0;
    cin >> T;
    for (int i = 10000; i >= 1; i /= 100) {
        time2[cur++] = T / i;
        T %= i;
    }

    long long day1 = time1[2], day2 = time2[2];

    // 计算相对时间，以该年的一月一日起到那一天的时间
    for (int i = 1; i < 13; i++) {
        if (time1[1] > i) {
            day1 += month[i];
        }
        if (time2[1] > i) {
            day2 += month[i];
        }
    }
    if (time1[1] > 2 && isRUN(time1[0])) {
        day1++;
    }
    if (time2[1] > 2 && isRUN(time2[0])) {
        day2++;
    }

    // 对后一个日期再计算年份之差，得到绝对时间，注意谁大谁小
    if (time1[0] == time2[0]) {
        cout << abs(day2 - day1) + 1 << endl;
    } else if (time1[0] < time2[0]) {
        for (int i = time1[0]; i < time2[0]; i++) {
            day2 += isRUN(i) ? 366 : 365;
        }
        cout << day2 - day1 + 1 << endl;
    } else {
        for (int i = time2[0]; i < time1[0]; i++) {
            day1 += isRUN(i) ? 366 : 365;
        }
        cout << day1 - day2 + 1 << endl;
    }
}