/*
获取给定数组的所有子集
通过二进制枚举解决
*/
#include<vector>
#include<iostream>
#include"tools.h"
using namespace std;

//函数的声明
vector<vector<int>> subset(vector<int>& set);
// template <class T>
// void print2D(const vector<vector<T>>& a, char sep = ',');

//用于测试的集合
vector<int> test = {1, 2, 3};
vector<vector<int>> tes;

//被别的文件调用时，为了防止main函数的冲突，可加预处理指令
//此处只做演示，无目的，因为该文件无需被引用
int main(){
    tes = subset(test);
    print2D(tes);

}

//这里采用核心代码模式，暂不考虑输入输出
//后续加入了输出函数
vector<vector<int>> subset(vector<int>& set){
    vector<vector<int>> end;
    int n = set.size();
    //子集的个数有2的n次方个，通过位运算符<<来得到对应的个数，更为方便快捷
    //虽然此处用1 << n有int位数不够而溢出的风险，但是写1LL又没什么必要，太大的集合时间开销大
    for (int i = 0; i < (1 << n); i++){
        //存储子集的动态数组
        vector<int> res;
        //然后对于每一个二进制数字
        for (int j = 0; j < n; j++){
            //这里，通过>>运算符和逐位与&来获取i的二进制的第j位是0还是1
            //此时由于1的二进制是000...0001，从而达到了只取第j位的目的，1作为掩码
            if ((i >> j) & 1){
                res.push_back(set[j]);
            }
        }
        end.push_back(res);
    }
    return end;
}
