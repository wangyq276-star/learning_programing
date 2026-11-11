/*
描述
双指针是极其常用的算法，这是必须学会，也是不可不会的。
但是双指针看似简单，背后的思想并不容易掌握。
小华深谙此理，为了帮助小鲁一步一步的掌握这编程利器，他为小鲁精心设计了三道题：
第一题：
给定一个目标值 target，请你在不包含重复元素的按升序排列的整数数组 a中，
找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。
例如:给定 a= [2, 7, 10, 15], target = 17，
因为 a[1] + a[2] = 7 + 10 = 17，所以返回 [1 2]

输入
输入数据为2行，第一行有两个整数 target和n，
其中target代表要搜索的目标和，n表示数组a的元素个数
第二行表示数组a的n个数，每个元素用空格隔开。

输出
输出和为target的两个元素的下标 i j ，其中(i<j)。
*/
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int nums[N] = {0};
int t, n;

void findSumTar(int l, int r);

int main(){
    cin >> t >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    findSumTar(0, n - 1);
}

void findSumTar(int l, int r){
    if (nums[l] + nums[r] == t){
        cout << l << ' ' << r << endl;
        return;
    }
    //如果和大于 t 说明右端的数太大，要减一
    if (nums[l] + nums[r] > t){
        findSumTar(l, r - 1);
    }else{
        findSumTar(l + 1, r);
    }
}