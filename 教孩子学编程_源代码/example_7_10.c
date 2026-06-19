#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,j;
    printf("输入一个整数：");
    scanf("%d",&n);
    for(i=1;i<=n;i++)         //控制行的输出
    {
        for(j=1;j<=n-i;j++)  //控制列的输出
            printf("　");     //每一列打印n-i个空格
        for(j=1;j<=i;j++)    //控制列的输出
            printf("＊");     //每一列打印i个“＊”
        printf("\n");        //当前行结束，输出换行符
    }
    system("pause");
    return 0;
}
