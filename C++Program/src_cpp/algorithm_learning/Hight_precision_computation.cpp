#include<iostream>
#include <string>

using namespace std;

/*
这段高精度计算代码目前只能实现正整数的加减乘除的逻辑
还比较局限
*/

const int N = 1e5 + 10;

struct Bignum{
//成员变量
    private:

    int numSto[N] ={0};
    int len = 0;
    char sign = '+';

//成员方法
    public:

    //构造器
    Bignum(){
        this->store("0");
    }

    //将字符串存储的数转存到数组中并对sign、len进行初始化
    void store(const char* s){
        int start = 0;

        //判断正负
        if (s[0] == '-'){ 
            this->sign = '-'; 
            start = 1; 
        }else{
            this->sign = '+';
        }

        //得到结束位置
        int end = start;
        while (s[end] != '\0'){
            end++;
        }
        this->len = end - start;

        // 逆序填入                   
        for (int k = end - 1, p = 0; k >= start; k--, p++)
            this->numSto[p] = s[k] - '0';   
        
        //校验数字，预防多个0的情况
        while (len > 1 && numSto[len-1] == 0){
            len--;
        }  
        if (len <= 0){
            len = 1; 
            numSto[0] = 0; 
            sign = '+'; 
        }
    }
    
    //展示数字
    void showNum(){
        //判断是否为0或负数等非法状态
        if (this->len <= 0){
            cout << "Wrong" << endl;
            return;
        }else if (this->len == 1 && this->numSto[0] == 0){
            cout << "0" << endl;
            return;
        }

        //判断符号
        if (this->sign == '-'){
            cout << '-';
        }

        //逆序输出这个数字
        for (int i =  this->len - 1; i >= 0; i--){
                cout << this->numSto[i];
        }
        cout << endl;
    }

    //判断两数绝对值
    short abs(const Bignum& num1, const Bignum& num2){

    }

    //定义相加函数，要考虑两个数可能为负数的情况
    static void addHuge(const Bignum& num1, const Bignum& num2, Bignum& end){

        int tol, rest = 0;
        int max = num1.len > num2.len ? num1.len : num2.len;

        //如果都是正数或负数，一位一位计算
        if (num1.sign == num2.sign){

            char* endNum = new char[num1.sign == '-' ? max + 3 : max + 2];
            //先得到结果的正负
            endNum[0] = num1.sign == '-' ? '-' : '0';
            endNum[num1.sign == '-' ? max + 2 : max + 1] = '\0';
            for (int i = 0; i < max + 1; i++){
                tol = rest;
                if (i < num1.len){
                    tol += num1.numSto[i];
                }
                if (i < num2.len){
                    tol += num2.numSto[i];
                }
                endNum[max + 1 - i] = char('0' + tol % 10);
                rest = tol / 10;
            }
            end.store(endNum);
            delete[] endNum;//注意释放内存

            //对于最后一位，要检查是否有进位，防止len长度出错
            if (end.len > 1 && end.numSto[end.len - 1] == 0){
                end.len--;
            }

            //如果异号，调用减法函数
        }else if(num1.sign == '-' && num2.sign == '+'){
            subHuge(num2, num1, end);
        }else if(num1.sign  == '+' && num2.sign == '-'){
            subHuge(num1, num2, end);
        }
    }

    //定义相减函数,注意判断绝对值大小
    static void subHuge(const Bignum& num1, const Bignum& num2, Bignum& end){
        
        int tol, rest = 0;
        int max = num1.len > num2.len ? num1.len : num2.len;

        if (num1.len == num2.len){
            end.store("0");
            return;

        }else if (  ){

            char* endNum = new char[num1.sign == '-' ? max + 3 : max + 2];
            //先得到结果的正负
            endNum[0] = num1.sign == '-' ? '-' : '0';
            endNum[num1.sign == '-' ? max + 2 : max + 1] = '\0';
            for (int i = 0; i < max + 1; i++){
                tol = rest;
                if (i < num1.len){
                    tol += num1.numSto[i];
                }
                if (i < num2.len){
                    tol += num2.numSto[i];
                }
                endNum[max + 1 - i] = char('0' + tol % 10);
                rest = tol / 10;
            }
            end.store(endNum);
            delete[] endNum;//注意释放内存

            //对于最后一位，要检查是否有进位，防止len长度出错
            if (end.len > 1 && end.numSto[end.len - 1] == 0){
                end.len--;
            }
        }
    }
};




//此处默认num1 - num2

// void subHuge(string& num1, string& num2, int* end, int& len){
//     //先将两个字符串储存的大数转存到数组中并计算数字的位数
//     store(num1, N1, len1, sign1);
//     store(num2, N2, len2, sign2);

//     int tol, rest;
//     int max = num1.size() > num2.size() ? num1.size() : num2.size();

//     //假设num1大于num2
//     //一位一位计算
//     for (int i = 0; i < max + 1; i++){
//         tol = N1[i] - N2[i];
//         if (tol < 0){

//         }
//     }
//     //对于最后一位，要检查是否有进位，防止len长度出错
//     if (len > 1 && *(end + len - 1) == 0){
//         len--;
//     }
// }

//内存占用较大的对象一定要定义在外面，不然主函数的栈空间会爆满
Bignum N1, N2, reslut;
char num1[N],num2[N];

int main(){
    

    N1.showNum();
    N2.showNum();

    cout << "input tne Bignum:" << endl;
    cin >> num1 >> num2;

    N1.store(num1);
    N2.store(num2);
    N1.showNum();
    N2.showNum();

    Bignum::addHuge(N1, N2, reslut);
    reslut.showNum();

    Bignum::subHuge(N1, N2, reslut);
    reslut.showNum();

}