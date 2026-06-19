#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
	int *p1, *p2, *p3;
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    *p1 = 100;
    *p2 = *p1 % 2;
    if(*p1 != *p2) p3 = p1;
    else p3 = p2;
    printf("%d\n%d\n%d\n",*p1,*p2,*p3);
	system("pause");
	return 0;
}
