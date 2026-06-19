#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	system("color 70");
    int number,a,b,c,d,s;
    srand(time(NULL));
    number = rand()%9000+1000;
    a = number % 10;
    b = number / 10 % 10;
    c = number / 100 % 10;
    d = number / 1000;
    s = a+b+c+d;
    printf("\n随机生成四位整数：%d\n",number);
    printf("各位数字的和：%d+%d+%d+%d=%d\n",d,c,b,a,s);
    printf("\n\n");
	system("pause");
	return 0;
}
