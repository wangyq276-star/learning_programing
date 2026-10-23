/*
该文件保存一些用于输出一二维列表的函数
*/
#pragma once                   

#include <iostream>
#include <vector>
//头文件不要用命名空间限制语句using namespace，防止头文件的指令污染其他文件

template <class Container>
void print2D(const Container& a, char sep = ',') {
    std::cout << "vector" << std::endl;
    for (const auto& row : a) {
        std::cout << '[';
        bool first = true;
        for (const auto& val : row) {
            if (!first) std::cout << sep;
            std::cout << val;
            first = false;
        }
        std::cout << ']' << std::endl;
    }
    std::cout << std::endl;
}

void show(const int * ls, int len){
    for (int i = 0; i < len; i++){
        std::cout << ls[i] << " ";
    }
    std::cout << std::endl;
}