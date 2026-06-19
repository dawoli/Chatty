#include <stdio.h>
#include <stdlib.h>
int main(){
    float PI=3.14159;     //定义PI为float型并赋值为3.14159
    int S,C,r=5;                         //定义S、C、r为int型
    S=r*r*PI;     //PI以double型参与计算，结果也为double型，
                  // 因S为int型，故结果被自动转换为int型赋值给S
    C=2*r*PI;     //PI以double型参与计算，结果也为double型，
                  // 因C为int型，故结果被自动转换为int型赋值给C
    printf("\nr=5的圆面积为：%d\n",S);
    printf("r=5的圆周长为：%d\n",C);
    system("pause");
    return 0;
}
