#include <stdio.h>
#include <stdlib.h>
int x=10;                                         // A：文件作用域/
/*--自定义函数--*/
void print_x(void)
{
    printf("x=%d  ",x);
}
/*--主函数--*/
int main()
{
    system("color 70");
    int i;
    int x = 999;                               // B：块作用域/
    print_x();            //-----(1)
    printf("//循环前print_x函数打印(1)\n"); 
    printf("x=%d  ",x);  //-----(2)
    printf("//循环前printf函数打印(2)\n"); 
    for(i=0;i<5;i++)
    {
        int x = i*100;                     // C：块作用域/
        printf("x=%d",x);//-----(3)
        printf("   //第%d轮循环(3)\n",i+1);
    } 
    print_x();            //-----(4)
    printf("//循环后print_x函数打印(4)\n"); 
    printf("x=%d  ",x);  //-----(5)
    printf("//循环后printf函数打印(5)\n\n"); 
    system("pause");
    return 0;
}

