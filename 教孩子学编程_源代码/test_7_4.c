#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++){
		for(j=1;j<=abs(i-n);j++)
			printf(" ");
		for(j=1;j<=(n-abs(i-n))*2-1;j++)
			printf("#");
        printf("\n");
    }
	system("pause");
	return 0;
}
