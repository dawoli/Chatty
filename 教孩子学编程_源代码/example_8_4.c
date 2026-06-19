#include <stdio.h>
#include <stdlib.h>
int prime(int x)     //判断x是否是质数的函数并打印质数
{
	int j=2;
    if(x==2) {
		printf("%d ",x);
        return 1;
    }	
    while(x%j!=0 && j<=sqrt(x))
		j++;
    if(x%j==0) return 0;
    else {
		printf("%d ",x);
        return 1;
    }		
}
int main()
{
	int i,n,ans=0;
    printf("请输入一个大于2的正整数：");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
		if(prime(i)) ans++;
    printf("\n2~%d之间有%d个质数。\n",n,ans);
	system("pause");
	return 0;
}
