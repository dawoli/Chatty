#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
    scanf("%d",&n);
    switch(n%5)
    {
		case 0: printf("%d ",n); break;
		case 1: printf("%d ",n); n=n+4; break;
		case 2: printf("%d ",n); n=n+3; break;
		case 3: printf("%d ",n); n=n+2; break;
		case 4: printf("%d ",n); n=n+1; break;
    }
    printf("%d\n",n);
	system("pause");
	return 0;
}
