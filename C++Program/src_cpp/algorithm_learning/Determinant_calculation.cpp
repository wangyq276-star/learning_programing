/*
本程序用于实现任意 n 阶行列式的计算
*/
#include<iostream>
#include<vector>
//加入了 fabs 函数，便于得到小数的绝对值
#include<cmath>
//加入了 fixed 、setprecision() 函数，便于控制结果输出的小数位数
#include<iomanip>

using namespace std;

//建立一个动态数组来装行列式
vector<vector<double>> det;
int len;

double detCal(vector<vector<double>> det);

int main(){

    cout << "Please input the level of the determinant: " << endl;
    cin >> len;
    det.resize(len, vector<double>(len));

    cout << "Please input the whole determinant: " << endl;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            cin >> det[i][j];
        }
    }

    cout << "reslut is : " << fixed << setprecision(10) << detCal(det) << endl;
}

double detCal(vector<vector<double>> det){
    int level = det.size();
    short sign = 1;
    double res = 1;

    double norm = 0;
    const double eps = 1e-12;

    //因为有小数，会有精度损失
    //先用迭代器获取该行列式的数字量级，便于判断什么时候该把数字判断为0
    for (auto& row : det){
        for (double x : row){
            norm = max(norm, fabs(x));
        }      
    }
    
    for (int j = 0; j < level; j++){
        short exchgeLine = j;
        double maxEle = fabs(det[j][j]);

        //先找到绝对值最大的元素当主元
        for (int i = j + 1; i < level; i++){
            if (fabs(det[i][j]) > maxEle){
                exchgeLine = i;
                maxEle = fabs(det[i][j]);
            }
        }

        //如果行列式有一列为0，直接就等于0
        //这里采用精度判断
        if (maxEle < eps * max(1.0, norm)){
            return 0.0;
        }

        //把元素最大的给放在第 j 行，然后用高斯消元变为上三角行列式，这样误差比较小
        if (exchgeLine != j){
            //换行一定要变号
            sign = -sign;
            for (int t = 0; t < level; t++){
                swap(det[j][t], det[exchgeLine][t]);
            }
        }

        //结果乘以对角线元素
        res *= det[j][j];
        
        for (int m = j + 1; m < level; m++){

            //先得到每一列数的消元因子
            double factor = (double)det[m][j] / det[j][j];
            //再进行消元
            for (int n = j; n < level; n++){
                det[m][n] -= det[j][n] * factor;
            }
        }
    }
    return sign * res;
}
/*
测试用例：

Please input the level of the determinant: 
2
Please input the whole determinant: 
1 2
2 4
reslut is : 0

Please input the level of the determinant: 
10
Please input the whole determinant: 
0 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 2 2 2 2 2 2 2 2 2
1 2 3 3 3 3 3 3 3 3
1 2 3 4 4 4 4 4 4 4
1 2 3 4 5 5 5 5 5 5
1 2 3 4 5 6 6 6 6 6
1 2 3 4 5 6 7 7 7 7
1 2 3 4 5 6 7 8 8 8
1 2 3 4 5 6 7 8 9 9
1 2 3 4 5 6 7 8 9 10
reslut is : 1.0000000000

Please input the level of the determinant: 
10
Please input the whole determinant: 
6  2  4 -2 -4  2  4 -2 -4  4
4 -1 -4  2  4 -2 -4  2  4 -4
2 -1 -1  1  2 -1 -2  1  2 -2
6 -3 -6  4  6 -3 -6  3  6 -6
2 -1 -2  1  3 -1 -2  1  2 -2
4 -2 -4  2  4 -1 -4  2  4 -4
2 -1 -2  1  2 -1 -1  1  2 -2
6 -3 -6  3  6 -3 -6  4  6 -6
2 -1 -2  1  2 -1 -2  1  3 -2
4 -2 -4  2  4 -2 -4  2  4 -3
reslut is : -2.0000000000

*/