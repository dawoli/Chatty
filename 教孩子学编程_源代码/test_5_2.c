#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float a, b, c, p, s;    
    printf("请输入三角形的三条边长（空格分隔）：");
    scanf("%f %f %f",&a,&b,&c);
    p = (a+b+c)/2.0;
    s = sqrt(p*(p-a)*(p-b)*(p-c));  
    printf("三角形的面积是：");
	printf("%.2f\n",s);
	system("pause");
	return 0;
}
