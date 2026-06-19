#include <stdio.h>
#include <stdlib.h>
int isPrime(int num)
{
	int i;
    if(num<2) return 0;
    if(num<4) return 1;
    for(i=2; i*i<=num; ++i)
		if(num%i==0) return 0;
    return 1;
}
int main()
{
	int N;
    scanf("%d",&N);
    if(isPrime(N) == 1)
        printf("Yes\n");
    else
        printf("No\n");
	system("pause");
	return 0;
}
