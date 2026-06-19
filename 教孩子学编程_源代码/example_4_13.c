#include <stdio.h>
#include <stdlib.h>
int main(){
    float PI=3.14159;    //定义PI为float型并赋值为3.14159
    int S,C,r=5;                        //定义S、C、r为int型
    S=r*r*(int)PI;         //PI被强制转换为int型参与面积计算
    C=2*r*(int)PI;         //PI被强制转换为int型参与周长计算
    printf("\nr=5的圆面积为：%d\n",S);
    printf("r=5的圆周长为：%d\n",C);
    system("pause");
    return 0;
}
