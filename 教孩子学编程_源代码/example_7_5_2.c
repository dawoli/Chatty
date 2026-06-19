#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i;
    printf("输入一个大于1的整数：\n");
    scanf("%d",&n);
    if(n==2) printf("Yes\n");                  //处理2的判断
    else                                         //处理n>2的判断
    { 
        i=2;
        while(n%i!=0 && i<=sqrt(n))                //循环条件
            i++;
        if(n%i==0) printf("No\n");         //出现整除，非质数
        else printf("Yes\n");                   //否则，是质数
    }
    system("pause");
    return 0;
}

