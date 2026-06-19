#include <stdio.h>
#include <stdlib.h>
int main()
{
    system("color 70");
    int x1,x2,x3,n;
    printf("\n请输入桐桐的年龄（整数）：");
    scanf("%d",&n);
    x3=(n+1)*2;
    x2=(x3+4)*2;
    x1=(x2+5)*2;
    printf("\n妈妈给了%d岁的桐桐%d颗糖果！\n\n",n,x1);
    system("pause");
    return 0;
}
