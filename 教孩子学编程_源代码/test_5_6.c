#include <stdio.h>
#include <stdlib.h>
int main()
{
	float r,x,y;
    int n;
    printf("输入年利率r：");
    scanf("%f",&r);
    printf("输入存入本钱x：");
    scanf("%f",&x);
    printf("输入存款年数n：");
    scanf("%d",&n);
    y = x*pow((100+r)/100.0,n);
    printf("%.2f元存%d年后本利合计为：%.2f\n",x,n,y);
    printf("\n");
	system("pause");
	return 0;
}
