
#include <cstring>
#include <iostream>
using namespace std;

struct array{
    int * addrs = nullptr;
    int hold = 0;
    int len = 0;

    void resize(int capacity = 0){
        int new_capacity;
        if (addrs == nullptr){
            new_capacity = capacity == 0 ? 10 : capacity;
            addrs = new int[new_capacity];
            this->hold = new_capacity;
        }else{
            int * temp = addrs;
            new_capacity = (capacity != 0 && capacity > 2 * this->hold) ? capacity : 2 * this->hold;
            addrs = new int[new_capacity];
            memcpy(addrs, temp, sizeof(int) * this->len);
            delete[] temp;
            this->hold = new_capacity;
        }
    }

    //定义这两个用于迭代器的函数
    int * begin(){
        return addrs;
    }

    int * end(){
        return addrs + this->len;
    }

    void add(int value){
        if (hold <= len){
            resize();
        }

        this->addrs[len] = value;
        len++;
    }

    void show(){
        /*
        旧代码：
        for(int i = 0; i < len; i++){
            cout << addrs[i] << " ";
        }*/

        /*
        在使用范围for时要在结构体中定义begin和end函数
        然后使用const和引用可以避免函数的值拷贝，提高效率
        
        */
        for(const auto& i: * this){
            cout << addrs[i] << " ";
        }
    }
    ~array(){
        if (addrs != nullptr){
            delete[] addrs;
            addrs = nullptr;
            hold = 0;
            len = 0;
        }
    }
};

//测试顺序列表
int main(){
    array L;
    L.add(10);
    L.add(11);
    L.add(12);
    L.add(13);
    L.add(14);
    L.show();
}