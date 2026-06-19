#include <stdio.h>
#include <stdlib.h>
long int m;
long int fun(long int n){
	if(n==1) return 1;
    else return 2*fun(n-1)+10;
}
int main()
{
	scanf("%ld",&m);
    printf("%ld\n",fun(m));
	system("pause");
	return 0;
}
