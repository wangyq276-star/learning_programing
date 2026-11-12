/*
描述
看着小鲁AC了第一题，小华接着提出第二问：
给定一个目标值 target，请在整数数组 a中，找出三个元素(x,y,z) 使x+y+z==target。
请找到所有满足条件的三元组，并且请按从小到大的顺序输出所有合法的三元组。
注意：三元组中不允许包含重复数字，且输出的三元组中要求 x<y<z.
例如:给定target = 17，n=7, 数组a= [0, 2, 7, 10, 15,18,25]
结果返回两个三元组：(0,2, 15), (2,7,10)

输入
输入数据为2行，第一行有两个整数 target和n，其中target代表要搜索的目标和，n表示数组a的元素个数
第二行表示数组a的n个数，每个元素用空格隔开。

输出
输出所有满足和为target的三元组(x,y,z)，要求(x< y <z) 并且不允许有重复数字。
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int nums[N] = {0};
int n, k;

void findSumTar();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums, nums + n);

    findSumTar();
}

void findSumTar(){
    //先确定第一个指针，变化为双指针问题求解
    for (int i = 0; i < n - 2; i++){
        //对第一个元素进行去重
        if (i != 0 && nums[i] == nums[i + 1]){
            continue;
        }

        int l = i + 1, r = n - 1, tar = k - nums[i];

        while (l < r){
            if (nums[l] + nums[r] == tar){
                //如果三个元素互不相等才打印
                if (nums[i] != nums[l] && nums[i] != nums[r] && nums[l] != nums[r]){
                    cout << nums[i] << ' ' << nums[l] << ' ' << nums[r] << endl;
                }
                //跳过重复元素
                int left = nums[l], right = nums[r];
                while (l < r && nums[l] == left) l++;
                while (l < r && nums[r] == right) r--;
                continue;
            }else if (nums[l] + nums[r] > tar){
                r--;
                continue;
            }else if (nums[l] + nums[r] < tar){
                l++;
                continue;
            }
        }
    }
}