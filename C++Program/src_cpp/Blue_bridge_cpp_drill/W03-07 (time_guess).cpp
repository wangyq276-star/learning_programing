/*
描述
小明正在整理一批历史文献。这些历史文献中出现了很多日期。
小明知道这些日期都在1960年1月1日至2059年12月31日。
令小明头疼的是，这些日期采用的格式非常不统一
有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
更加麻烦的是，年份都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
比如02/03/04，可能是2002年03月04日，2004年02月03日或2004年03月02日。
给出一个文献上的日期，你能帮小明分析所有可能的日期对其对应吗？

输入
一个日期，格式是"AA/BB/CC"。
即每个'/'隔开的部分由两个0-9之间的数字（不一定相同）组成。

输出
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。
多个日期按从早到晚排列。
数据范围
0 ≤ A, B, C ≤ 9
*/
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;

int date[3];
bool isPlace[3] = {0};
int idx[3], id = 0;

vector<tuple<int, int, int>> Dates;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthR[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 采用 DFS 获取这三个数字的全排列
void isDate() {
    // 月份不能超过 12 ，天数不能为 0
    if (idx[1] > 12 || idx[1] < 1 || idx[2] < 1) {
        return;
    }
    /*
        关于年份：
        大于等于 60 小于 99 的只能是 19 开头， 大于 0 小于 60 的是 20
    */
    if (idx[0] >= 60) {
        idx[0] += 1900;
    } else {
        idx[0] += 2000;
    }

    // 天数不能超过该月最多天数（注意判断闰年）
    if (idx[2] > ((idx[0] % 4 == 0 && idx[0] % 100 != 0) || (idx[0] % 400 == 0)
                      ? monthR[idx[1]]
                      : month[idx[1]])) {
        return;
    }

    Dates.push_back({idx[0], idx[1], idx[2]});

    return;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    scanf("%d/%d/%d", &date[0], &date[1], &date[2]);

    idx[0] = date[0], idx[1] = date[1], idx[2] = date[2];
    isDate();
    idx[0] = date[2], idx[1] = date[0], idx[2] = date[1];
    isDate();
    idx[0] = date[2], idx[1] = date[1], idx[2] = date[0];
    isDate();

    // 对所得日期排序
    sort(Dates.begin(), Dates.end());
    // 去重
    Dates.erase(unique(Dates.begin(), Dates.end()), Dates.end());

    for (auto i : Dates) {
        printf("%d-%02d-%02d\n", get<0>(i), get<1>(i), get<2>(i));
    }
    return 0;
}