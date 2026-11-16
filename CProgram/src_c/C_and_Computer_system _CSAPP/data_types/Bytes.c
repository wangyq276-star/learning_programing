#include<stdio.h>

void show_bytes(unsigned char* start, int len);

int main(){
    int value1 = 123567890;
    //运用强制转换，把内存地址看作一个字符指针
    show_bytes((unsigned char*) &value1, sizeof(int));
    //输出 ：127f5d07

    float value2 = 12345.67890;
    show_bytes((unsigned char*) &value2, sizeof(float));
    //输出 ：b7e64046（这里是十六进制表示，要想看出符号位、阶码位、尾数位要先转为二进制）
    /*
    二进制表示：0100 0110 0100 0000 1110 0110 1011 0111
    不同的存储位：符号位->(0) 阶码位->(100 0110 0) 尾数位->(000 1110 0110 1011 0111)
    转换为二进制科学计数法：符号-> + 阶码-> E = 140 - 127(Bias 偏置) = 13 尾数-> 1.000 1110 0110 1011 0111(二进制下)
    (注意：当阶码位不为 0 时，默认整数部分是 1 )
    那么小数 12345.67890 就等价于 1.000 1110 0110 1011 0111(二进制下) * 2 ** (13)
    */
}

void show_bytes(unsigned char* start, int len){
    for (int i = 0; i < len; i++){
        printf("%.2x", *(start + i));
        /*
        我这台电脑的系统是Windows
        采用小端法规则，会将低位字节放在较低内存处，所有会被先打印出来
            例如：对于数字 1234567890
            小端法 ：(0x) 12 7f 5d 07
            大端法 ：(0x) 07 5d 7f 12
        */
    }
    printf("\n");
}