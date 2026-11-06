/*
以下使用单调递减的栈来获取在数组中某一数左侧理他最近且比他小的数
*/
#include<iostream>
#include<stack>

using namespace std;

const int N = 1e6 + 10;
int len;
int nums[N];

int findLNearBig(int* nums, int len, int findIndex);
int findRNearBig(int* nums, int len, int findIndex);
int findLNearSmall(int* nums, int len, int findIndex);
int findRNearSmall(int* nums, int len, int findIndex);

int main(){
    ios:: sync_with_stdio(0);
    cin.tie(0);

    cin >> len;
    for (int i = 1; i <= len; i++){
        cin >> nums[i];
    }

    int findIndex;
    cin >> findIndex;

    cout << findLNearBig(nums, len, findIndex) << endl;
    cout << findRNearBig(nums, len, findIndex) << endl;
    cout << findLNearSmall(nums, len, findIndex) << endl;
    cout << findRNearSmall(nums, len, findIndex) << endl;

}

/* 
    找到该元素 左 侧距离他最近且比他 大 的元素（没有就返回 0 ） 
    维护单调递减的栈，从左向右扫描
*/
int findLNearBig(int* nums, int len, int findIndex){
    stack<int> window;
    int index[len + 10] = {0};

    for (int i = 1; i <= len; i++){
        //因为是单调栈所以所有比新元素大的栈中元素都要扔掉，直到能够使之单调为止
        while(!window.empty() && nums[window.top()] <= nums[i]){
            window.pop();
        }

        //记录更新对应元素最近的比他大的元素的下标（没有就是数组初始化时默认的0）
        if (!window.empty()){
            index[i] = window.top();
        }

        window.push(i);
    }

    return nums[index[findIndex]];
}

/* 
    找到该元素 右 侧距离他最近且比他 大 的元素（没有就返回 0 ） 
    维护单调递减的栈，从右向左扫描
*/
int findRNearBig(int* nums, int len, int findIndex){
    stack<int> window;
    int index[len + 10] = {0};

    for (int i = len; i >= 1; i--){
        while(!window.empty() && nums[window.top()] <= nums[i]){
            window.pop();
        }

        if (!window.empty()){
            index[i] = window.top();
        }

        window.push(i);
    }

    return nums[index[findIndex]];
}

/* 
    找到该元素 左 侧距离他最近且比他 小 的元素（没有就返回 0 ） 
    维护单调递增的栈，从左向右扫描
*/
int findLNearSmall(int* nums, int len, int findIndex){
    stack<int> window;
    int index[len + 10] = {0};

    for (int i = 1; i <= len; i++){
        while(!window.empty() && nums[window.top()] >= nums[i]){
            window.pop();
        }

        if (!window.empty()){
            index[i] = window.top();
        }

        window.push(i);
    }

    return nums[index[findIndex]];
}

/* 
    找到该元素 右 侧距离他最近且比他 小 的元素（没有就返回 0 ） 
    维护单调递增的栈，从右向左扫描
*/
int findRNearSmall(int* nums, int len, int findIndex){
    stack<int> window;
    int index[len + 10] = {0};

    for (int i = len; i >= 1; i--){
        while(!window.empty() && nums[window.top()] >= nums[i]){
            window.pop();
        }

        if (!window.empty()){
            index[i] = window.top();
        }

        window.push(i);
    }

    return nums[index[findIndex]];
}