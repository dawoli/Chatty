#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N;
    printf("请输入一个整数：\n");
    scanf("%d",&N);
    if(N%7==0)
        {printf("Yes，%d能被7整除！\n",N);}
    else
        {printf("No，%d不能被7整除！\n",N);}
    system("pause");
    return 0;
}
