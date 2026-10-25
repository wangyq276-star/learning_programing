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
using namespace std;

const int N = 1e5 + 10;

int nums[N] = {0};
int target;

void Find_range(const int* List, int len, int target);

int main(){
    int n;

    cin >> n >> target;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    Find_range(nums, n, target);

    /*
    使用先找一个然后线性向两边扩展的方法时间复杂度还是O（N）
    因此，需要再次使用二分查找得到两侧的边界
    if (!flag){
        l = -1; r = -1;
    }else{
        l = idx; r = idx;
        while (nums[l] == target){
            l--;
        }
        while (nums[r] == target){
            r++;
        }
    }
    */
    
}

void Find_range(const int* List, int len, int target){
    if (len == 0){
        cout << "[-1,-1]" << endl;
        return;
    }

    int left = 0, right = len - 1, mid;

    while (left < right){
        mid = left + ((right - left) >> 1);
        if (List[mid] >= target){
            right = mid;
        }else if (List[mid] < target){
            left = mid + 1;
        }
    }

    int start = left;

    left = 0;right = len - 1;

    while (left < right){
        mid = left + ((right - left + 1) >> 1);
        if (List[mid] <= target){
            left = mid;
        }else if (List[mid] > target){
            right = mid - 1;
        }
    }

    int end = right;
    
    if (end >= start && List[start] == target){
        cout << '[' << start << ',' << end << ']' << endl;
    }else{
        cout << "[-1,-1]" << endl;
    }
    return;

}