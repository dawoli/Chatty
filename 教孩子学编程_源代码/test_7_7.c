#include<stdio.h>
#include <stdlib.h>
void main()
{
	long fib1=1,fib2=1,fib;    /*fib1:前一个月兔子数,fib2:前两个月兔子数,fib:当月兔子总数*/
	int i;
	printf("%2d：%-12ld %2d：%-12ld ",1,fib1,2,fib2);	/*输出第一个月和第二个月的兔子数*/
	for(i=3;i<=30;i++)
	{
		fib=fib1+fib2;			    /*迭代求出当前月份的兔子数*/
		printf("%2d：%-12ld ",i,fib);		    /*输出当前月份兔子数*/
		if(i%3==0)
			printf("\n");		    /*每行输出4个*/
		fib2=fib1;			        /*为下一次迭代作准备，求出新的fib2*/
		fib1=fib;			        /*求出新的fib1*/
	}
    printf("\n");
	system("pause");
	return 0;
}
