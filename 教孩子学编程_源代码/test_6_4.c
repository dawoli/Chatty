#include <stdio.h>
#include <stdlib.h>
int main()
{
	long N,D1,D10,D100;
    printf("请输入一个三位正整数：");
    scanf("%d",&N);
    D1 = N%10;
    D10 = N/10%10;
    D100 = N/100;
    if(D1*D1*D1+D10*D10*D10+D100*D100*D100==N)
		printf("Yes\n");
    else printf("No\n");
	system("pause");
	return 0;
}
