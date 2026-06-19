#include <stdio.h>
#include <stdlib.h>
int a;
void add2(int *x){
	*x += 10;
    printf("x=%d\n", *x);
}
int main()
{
	a = 0;
    add2(&a);
    printf("a=%d\n", a);
    system("pause");
	return 0;
}
