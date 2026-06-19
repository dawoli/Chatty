#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 123;
    double b = 3636.23456;
    printf("a=%d\n",a);
    printf("2*a=%d\n",2*a);
    printf("a=%2d\n",a);
    printf("%3lf\n",b);
    printf("%15.2lf\n",b);
    printf("%-15.2lf\n",b);
    printf("%.2lf\n",b);
	system("pause");
	return 0;
}
