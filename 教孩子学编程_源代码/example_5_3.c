#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
    float a,b,c,x;
    printf("\n请输入三个浮点数（空格分隔），然后回车：\n");
    scanf("%f %f %f",&a,&b,&c);
    x=20-a-b-c;
    printf("还应捡的第四块石头重量为：%.2f千克\n",x);
    printf("\n\n");
	system("pause");
	return 0;
}
