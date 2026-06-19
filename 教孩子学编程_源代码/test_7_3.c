#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N, S=0;
    scanf("%d",&N);
    //while(N)
    while(N!=0)
    {
		S += N%10;
        N /= 10;
    }
    printf("%d\n",S);
	system("pause");
	return 0;
}
