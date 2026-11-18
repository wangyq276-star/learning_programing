/*
描述
从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。
必须按升序排列所有方案。

输入
一个整数 n（1 ≤ n ≤ 15）。

输出
每行输出一种方案。
同一行内的数必须升序排列，相邻两个数之间用恰好 1 个空格隔开。
对于没有选任何数的方案，输出空行。
必须按字典序升序输出所有方案。
*/
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N] = {0};
int len = 0;

void plan(int n, int pos) {
    /*
        此处，我先尝试采用二进制枚举的方式解决
        但是二进制枚举所得的方案不是字典序，无法按要求输出

    for (int i = 0; i < (1 << n); i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    a[cur++] = j + 1;
                }
            }
            for (int t = 0; t < cur; t++) {
                cout << a[t] << ' ';
            }
            cout << '\n';
        }

    */

    /*
        接下来尝试 DFS
        把每个节点都打印出来，不一定要到叶子节点再打印
        这样相当于变相得到了不选下一个数的结果
    */
    for (int i = 1; i < pos; i++) {
        // 打印空行
        if (pos == 1) {
            break;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';

    for (int i = n; i >= pos; i--) {
        // 防止重复元素的出现
        if (pos != 1 && i == a[pos - 1]) {
            return;
        }
        a[pos] = i;
        plan(n, pos + 1);
        a[pos] = 0; // 无意义，仅作为回溯标志
    }

    /*
        题解代码：

    //这里的 u 相当于 pos ，用于记录递归（DFS）的深度
    void dfs(int u){
        //递归的退出窗口
        if (u > n) {
            bool first = true;
            for (int i = 1; i <= n; i++){
                //只打印选中元素，该技巧也适用于之前写的生成全排列的代码
                if (st[i]) {
                    if (!first) putchar(' ');
                    printf("%d", i);
                    first = false;
                }
            }
            putchar('\n');  // 空集 → 空行
            return;
        }
        dfs(u + 1);  // 不选 u
        st[u] = true;  // 选 u
        dfs(u + 1);
        st[u] = false; // 撤销
    }

    */
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    plan(n, 1);

    return 0;
}