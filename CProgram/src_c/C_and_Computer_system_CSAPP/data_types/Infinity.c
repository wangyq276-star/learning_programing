/*我们可以使用浮点数来得到正无穷或负无穷而不会因为除以 0 而报错*/
#include <stdio.h>

int main(){
    printf("%f", 1.0 / 0.0);//输出正无穷 ：1.#INF00
    return 0;
}