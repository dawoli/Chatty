#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,s1=0,s0=0;
    printf("输入一个正整数：\n");
    scanf("%d",&n);
    do
    {
        if(n%2==1)
            s1++;      //余数为1，则s1加1
        else
            s0++;      //余数为0，则s0加1
        n/=2;          //n=n/2
    }
    while(n!=0);     //非0，则重复“除2取余”转换
    printf("二进制序列中1的个数是：%d\n",s1);
    printf("二进制序列中0的个数是：%d\n",s0);
    system("pause");
    return 0;
}
