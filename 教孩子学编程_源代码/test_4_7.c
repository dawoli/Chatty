#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
    int a, b;
    double per;
    printf("请输入两个整数。\n");
    printf("整数a：");  scanf("%d",&a);
    printf("整数b：");  scanf("%d",&b);
    per = (double)a/b*100;
    printf("a是b的%.2f%%。\n\n",per); 
	system("pause");
	return 0;
}
