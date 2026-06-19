#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
    int a, b;
    double r;
    printf("请输入整数a和b的值：");
    scanf("%d%d", &a, &b);
    printf("a + b = %d\n",a+b);
    printf("a - b = %d\n",a-b);
    printf("a * b = %d\n",a*b);
    printf("a / b = %d\n",a/b);
    printf("a %% b = %d\n",a%b);
    printf("(a + b)/2 = %d\n",(a+b)/2);
    printf("a和b的平均值 = %f\n\n",(double)(a+b)/2);
        
    printf("请输入圆的半径：");
    scanf("%lf", &r);
    printf("半径为%.3f的圆的面积是：%.3f。\n\n", r, 3.14*r*r); 
	system("pause");
	return 0;
}
