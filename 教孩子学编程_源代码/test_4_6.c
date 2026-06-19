#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
    int a, b, c;
    int sum;
    double ave;
    printf("请输入三个整数。\n");
    printf("整数a：");  scanf("%d",&a);
    printf("整数b：");  scanf("%d",&b);
    printf("整数c：");  scanf("%d",&c);
    sum = a + b + c;    
    ave = (double)sum/3;
    printf("它们的合计值是%6d。\n",sum); 
    printf("它们的平均值是%6.2f。\n\n",ave); 
	system("pause");
	return 0;
}
