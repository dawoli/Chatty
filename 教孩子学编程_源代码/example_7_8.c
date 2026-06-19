#include <stdio.h>
#include <stdlib.h>
int main(){
    int i;
    double t;                //定义共需麦粒t立方米
    double s = 0;           //累加器初始化
    double n = 1;           //加数初始化
    for(i=1; i<=64; i++)  //重复64次
    {
        s += n;             //累加
        n *= 2;             //n=n*2,在前一个n的基础上再乘以2
    }
    t = s / (1.42*100000000);    //计算麦粒体积
    printf("共需%.0lf立方米的麦粒！\n",t);
    system("pause");
    return 0;
}
