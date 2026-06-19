/*
 我的第一个C语言程序。
 屏幕第1行显示“Hello，World！”；
 屏幕第2行显示“圆周率约等于3.14159”；
 （c）2017，壹创程序小组。
*/

#include <stdio.h>      //预处理指令#include包含头文件stdio.h
#include <stdlib.h>     //预处理指令#include包含头文件stdlib.h
#define PI 3.14159      //预处理指令#define定义常量PI的值

int main()       //main 主函数（每一个C程序都必须包含它）
{                  //函数体开始符
printf("Hello,World!\n");        //printf 函数
printf("圆周率约等于%f\n",PI);    //printf 函数
system("pause");                  //system函数
return 0;    //函数返回值
}                  //函数体结束符
