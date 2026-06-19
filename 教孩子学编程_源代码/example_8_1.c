#include <stdio.h>
#include <stdlib.h>

/*---自定义函数Max2：返回较大值---*/
int Max2 (int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

/*---主函数---*/ 
int main()
{
    int n1,n2;
    puts("请输入两个整数。\n");
    printf("整数1：");  scanf("%d",&n1);
    printf("整数2：");  scanf("%d",&n2); 
    printf("较大的值是%d \n",Max2(n1,n2));  //调用Max2函数
    system("pause");
    return 0;
}

