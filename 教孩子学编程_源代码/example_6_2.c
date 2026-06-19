#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,t;
    printf("请任意输入三个数（空格分隔）：\n");
    scanf("%d %d %d",&a,&b,&c);
    if (a<b) {t=a; a=b; b=t;}    //如果a<b，则交换a和b的值
    if (a<c) {t=a; a=c; c=t;}    //如果a<c，则交换a和c的值
    if (b<c) {t=b; b=c; c=t;}    //如果b<c，则交换b和c的值
    printf("从大到小排列为：%d %d %d\n",a,b,c);
    system("pause");
    return 0;
}
