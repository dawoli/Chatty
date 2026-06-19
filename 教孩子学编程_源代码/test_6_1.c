#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
    printf("请输入一个整数：");
    scanf("%d",&n);    
	if(n%2)
		printf("%d是奇数。\n",n);
    else
		printf("%d是偶数。\n",n);
	system("pause");
	return 0;
}
