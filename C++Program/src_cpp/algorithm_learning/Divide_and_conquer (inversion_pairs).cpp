/*
洛谷（https://www.luogu.com.cn/problem/P1908）

题目描述：
猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。
最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：
对于给定的一段正整数序列，逆序对就是序列中 a_i > a_j 且 i < j 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。
注意序列中可能有重复数字。

输入格式：
第一行，一个数 n，表示序列中有 n 个数。
第二行 n 个数，表示给定的序列。序列中每个数字不超过 10⁹。

输出格式：
输出序列中逆序对的数目。
*/
#include<iostream>

using namespace std;

//先运用归并排序再在此过程中统计逆序对会轻松很多
const int N = 1e6 + 10;
int nums[N] = {0};
int temp[N] = {0};

long long numOfInvPairs(int* List, int left, int right);

int main(){
    //尝试使用快速 IO 这个小技巧
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << numOfInvPairs(nums, 0, n - 1) << endl;
}

long long numOfInvPairs(int* List, int left, int right){
    
    //使用静态变量，可以让所有的函数共享一个值，但缺点是只能调用一次这个函数，因为无法使它归零
    /*
    
    static long long count = 0;
    
    */
    
    //以下换一种写法来避免这个弊端

    long long count = 0;

    if (left >= right){
        return 0;
    }

    //使用位运算符进行除以二的操作，更快速
    int mid = left + ((right - left) >> 1);

    //采用递归完成排序，其结果默认有序
    //这里让 count 加上前面递归所得的逆序数，这也是为什么要设返回值为 long long 的原因（同时防止数据溢出）
    count += numOfInvPairs(List, left, mid);
    count += numOfInvPairs(List, mid + 1, right);

    //借助辅助数组完成有序数组的合并（难点）
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right){
        if (List[i] <= List[j]){
            temp[k++] = List[i++];
        }else{
            //如果顺序相反，并且由于已经排过序了，那么所有在 mid 和 i 中间的数就都大于 j ，便于统计
            count += mid - i + 1;
            temp[k++] = List[j++];
        }
    }
    while (i <= mid){
        temp[k++] = List[i++];
    }
    while (j <= right){
        temp[k++] = List[j++];
    }

    for (int t = 0; t < k; t++){
        List[t + left] = temp[t];
    }

    return count;
}