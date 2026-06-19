#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,r;
    printf("输入两个正整数（空格分隔）：\n");
    scanf("%d %d",&m,&n);
    r = m % n;       //r取m除以n的余数
    while(r!=0)      //辗转相除
    {
        m = n;        //小数给m
        n = r;        //余数给n
        r = m % n;   //r再次取m除以n的余数
    }
    printf("最大公约数是%d\n",n);
    system("pause");
    return 0;
}
