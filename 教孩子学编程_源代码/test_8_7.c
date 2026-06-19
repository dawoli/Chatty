#include <stdio.h>
#include <stdlib.h>
double sum(int n)
{
	if(n>1)
		return sum(n-1)+n*1.0/(n+1);
    else
		return 0.5;
}
int main()
{
	int i;
    printf("输入一个正整数：\n");
    scanf("%d",&i);
    printf("%.6lf\n",sum(i));
	system("pause");
	return 0;
}
