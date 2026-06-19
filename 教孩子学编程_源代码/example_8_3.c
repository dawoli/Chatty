#include <stdio.h>
#include <stdlib.h>
long int fac(int x)
{
	int i;
    long int s = 1;
    for(i=1;i<=x;i++)
		s *= i;
    return s;
}
int main()
{
	int m, n;
    printf("ÊäÈëmºÍn£¨m¡Ü10,n¡Üm£©:\n");
    scanf("%d %d",&m, &n);
    printf("C(m,n)=%ld\n",fac(m)/(fac(m-n)*fac(n)));
	system("pause");
	return 0;
}
