/* 读取两个整数显示它们的商和余数 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    system("color 70"); 
	int a, b;
    puts("请输入两个整数：");
    printf("整数a：");  scanf("%d",&a);
    printf("整数b：");  scanf("%d",&b);
    printf("a/b = %d\n", a/b);
    printf("a%%b = %d\n", a%b);
    printf("\n");
	system("pause");
	return 0;
}
