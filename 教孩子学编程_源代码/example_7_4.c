#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i=2;
    printf("输入一个正整数：\n");
    scanf("%d",&n);
    printf("%d=",n);
    do
    {
        while(n%i==0)        //如果i是n的质因子，则反复分解出i
        {
            printf("%d*",i); //输出质因子和一个乘号
            n /= i;            //n=n/i,用整除后的商作为新的被除数
        }
        i++;              //生成新的i
    }while(i<n);
    printf("%d\n",n);  //输出最后一个质因子n
    system("pause");
    return 0;
}
