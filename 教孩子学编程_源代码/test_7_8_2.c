#include<stdio.h>
#include <stdlib.h>
main()
{
	int m,n,temp,b,lcw,k; /* b存储两数相除得到的余数*/
	printf("Input m & n:");
	scanf("%d%d",&m,&n);
    k = m*n;
	if(m<n)              /*比较大小，使得m中存储大数，n中存储小数*/
	{
		temp=m;
		m=n;
		n=temp;
	}
    b = m%n;
    while(b!=0)          /* 辗转相除法求得最大公约数*/
    {
		m = n;
        n = b;
        b = m%n;
    }
    lcw = k/n;
	printf("The LCW of %d and %d is: %d\n",m,n,lcw);
    printf("\n");
	system("pause");
	return 0;
}
