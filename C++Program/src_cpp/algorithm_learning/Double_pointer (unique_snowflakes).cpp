/*
洛谷(https://www.luogu.com.cn/problem/UVA11572)

题目描述：
企业家 Emily 有一个很酷的主意：把雪花包起来卖。
她发明了一台机器，这台机器可以捕捉飘落的雪花，并把它们一片一片打包进一个包裹里。
一旦这个包裹满了，它就会被封上送去发售。

Emily 的公司的口号是“把独特打包起来”，为了实现这一诺言，一个包裹里不能有两片一样的雪花。
不幸的是，这并不容易做到，因为实际上通过机器的雪花中有很多是相同的。
Emily 想知道这样一个不包含两片一样的雪花的包裹最大能有多大。
她可以在任何时候启动机器，但是一旦机器启动了，直到包裹被封上为止，所有通过机器的雪花都必须被打包进这个包裹里。
当然，包裹可以在任何时候被封上。

输入格式：
第一行是测试数据组数 T。
对于每一组数据：
第一行是通过机器的雪花总数 n（n ≤ 10⁶）。
下面 n 行，每行一个在 [0, 10⁹] 内的整数，标记了这片雪花。当两片雪花标记相同时，这两片雪花是一样的。

输出格式：
对于每一组数据，输出最大包裹的大小，即最长的不包含重复元素的连续子序列长度
*/
#include<iostream>
//借助哈希表进行相同和不同元素的查找与判断
#include"search_tools.h"
#include<vector>

using namespace std;

const int N = 1e6 + 100;
//数据组数
int T;
//雪花数
int n;
//用于存储雪花的标记
int snow[N] = {0};
vector<vector<int>> snow_hash = {{0}};

int findSub(const int* arr, int len, vector<vector<int>>& hashTable);

int main(){
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> snow[j];
        }
        //实现找子列的逻辑
        findSub(snow, n, snow_hash);
        //重置数列
        for (int j = 0; j < n; j++){
            snow[j] = 0;
        }
    }
}

//嘻嘻，别想了，双循环必然超时
/*
int findSub(const int* arr, int len, vector<vector<int>>& hashTable){
    int length = 0;
    int longest = 0;
    //先观察这个数与之前的数想不想同（即能不能通过哈希表找到）不能就加入到哈希表中，能找到就退出
    for (int i = 0; i < len; i++){
        for (int j = i; j < len; j++){
            if (!(searchtools::hash_search(hashTable, arr[j]))){
                break;
            }else{
                searchtools::hash_add(hashTable, arr[j]);
                length++;
            }
        }
        if (length > longest){
            longest = length;
        }
        length = 0;
        if (len - i < longest){
            break;
        }
    }
    cout << longest << endl;
    return longest;
}
*/

