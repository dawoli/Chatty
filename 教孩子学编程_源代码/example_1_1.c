#include "stdio.h"                   //引入标准输入输出头文件
main()                                                 //主函数
{ 
    int a,b,c;                    //定义a、b、c三个整数型变量
    a=10; b=20;                          //a赋值10，b赋值20
    c=a+b;                       //计算a+b的和，并把它赋值给c
    printf("%d+%d=%d\n",a,b,c);      //屏幕打印“10+20=30”

    //system("pause");
    //return 0;
} 
