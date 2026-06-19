#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b,c,Count=0;
    for(a=0;a<=2;a++)                   //枚举50元钞票的可能张数
        for(b=0;b<=5;b++)               //枚举20元钞票的可能张数
            for(c=0;c<=10;c++)          //枚举10元钞票的可能张数
                if(50*a+20*b+10*c==100) //判断是否是有效兑换组合
                { 
                    Count++;
                    printf("50:%d  20:%d  10:%d\n",a,b,c);
                }
    printf("100元钱共有以上%d种兑换方案！\n",Count);
    system("pause");
    return 0;
}
