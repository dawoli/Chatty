#include <stdio.h>
#include <stdlib.h>
int main()
{
	float a,b,c,s;
    printf("输入长方形的两条边长（空格分隔）：");
    scanf("%f %f",&a,&b);
    c = (a+b)*2.0;
    s = a*b;
    printf("长方形的周长是：%.2f\n",c);
    printf("长方形的面积是：%.2f\n",s);
    printf("\n");
	system("pause");
	return 0;
}
