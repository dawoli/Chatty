#include <stdio.h>
#include <stdlib.h>
int main()
{
    int k;
    long int n=0;
    long double Sn=0;
    printf("输入一个整数");
    printf("(1-15)：\n");
    scanf("%d",&k);
    do
    {
        n++;
        Sn += 1.0/n;
    }while(Sn<=k); 
    printf("最小的n是");
    printf("%ld\n",n);
    system("pause");
    return 0;
}
