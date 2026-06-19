#include <stdio.h>
int main()  
{  
    int sum,i;     //定义变量的语句  
    sum=0;         //赋值语句
    i=100;         //赋值语句
    if(i>0)
        {
        sum=sum+i;
        i=i-1;
        }
    else 
        printf("i的值不大于0!");
    sum=0;i=0;      //赋值语句
    while(i<=100)
        {
        sum=sum+i;
        i=i+1;
        }
    printf("1到100的和是%d",sum);   //调用printf 函数语句
    system("pause");     //调用system函数暂停程序运行的语句
    return 0;                                   //函数返回语句
}
