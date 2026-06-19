#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a=41, b=44;
    printf("a和b的平均值为：%d \n",(a+b)/2);
    printf("a和b的平均值为：%f \n",(a+b)/2.0);
    printf("a和b的平均值为：%.2f \n",(double)(a+b)/2);
	system("pause");
	return 0;
}
