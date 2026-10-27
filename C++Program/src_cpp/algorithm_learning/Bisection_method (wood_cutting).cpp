/*
洛谷（https://www.luogu.com.cn/problem/P2440）

题目描述：
木材厂有 n 根原木，现在想把这些木头切割成 k 段长度均为 l 的小段木头（木头有可能有剩余）。
当然，我们希望得到的小段木头越长越好，请求出 l 的最大值。
木头长度的单位是 cm，原木的长度都是正整数，我们要求切割得到的小段木头的长度也是正整数。
例如有两根原木长度分别为 11 和 21，要求切割成等长的 6 段，很明显能切割出来的小段木头长度最长为 5。

输入格式：
第一行是两个正整数 n, k，分别表示原木的数量，需要得到的小段的数量。
接下来 n 行，每行一个正整数 Li，表示一根原木的长度。

输出格式：
仅一行，即 l 的最大值。
如果连 1cm 长的小段都切不出来，输出 0
*/

/*
因为二分算法的前提是有序数组，所以使用二分实际上是利用了数组的有序性来降低时间复杂度
那么就要从中找寻到有序数组
本题目，根据暴力枚举算法，原本是要从 0 ~ max(woods) 的，
但这是一个有序数组，因此使用二分来不断缩小区间从而找到那个临界的值
*/
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
//原木的数量和统一长度的数量
int n, k;
int woods[N] = {0};

int findMinLen(int* List, int num, int conNum);
int max(int* List, int num);

int main(){
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> woods[i];
    }

    cout << findMinLen(woods, n, k) << endl;
    
}

int findMinLen(int* List, int num, int conNum){
    int left = 0, right = max(List, num), mid;
    long long totalNum = 0;

    //通过二分寻找比暴力枚举寻找更有效率
    while(left < right){
        mid = left + ((right - left + 1) >> 1);
        totalNum = 0;

        /*
        for (int i = 0; i < num; i++){
            totalNum += List[i] / mid;
        }
        if (totalNum > conNum){
            left = mid + 1;
        }else if (totalNum < conNum){
            right = mid - 1;
        }else if (totalNum == conNum){
            return mid;
        }
        */

        for (int i = 0; i < num; i++){
            totalNum += List[i] / mid;
        }

        if (totalNum >= conNum){
            left = mid;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

int max(int* List, int num){
    int Max = List[0];
    for (int i = 0; i < num; i++){
        Max = List[i] > Max ? List[i] : Max;
    }
    return Max;
}