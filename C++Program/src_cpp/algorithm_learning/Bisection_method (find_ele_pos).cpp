/*
力扣（https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/）

题目描述：
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
*/
#include<iostream>
#include"search_tools.h"
using namespace std;

const int N = 1e5 + 10;

int nums[N] = {0};
int targer;

int main(){
    int n;
    int idx;
    int l, r;
    
    cin >> n >> targer;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    bool flag = searchtools::Binary_search(nums, n, targer, idx);

    /*
    使用先找一个然后线性向两边扩展的方法时间复杂度还是O（N）
    因此，需要再次使用二分查找得到两侧的边界
    if (!flag){
        l = -1; r = -1;
    }else{
        l = idx; r = idx;
        while (nums[l] == targer){
            l--;
        }
        while (nums[r] == targer){
            r++;
        }
    }
    */
    
    cout << '[' << l + 1 << ',' << r - 1 << ']' << endl;
    
}