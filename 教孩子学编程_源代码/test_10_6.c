#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
	*x += *y; *y = *x-*y; *x -= *y;
}
void sort(int *num1, int *num2, int *num3)
{
	if(*num1>*num2) swap(num1,num2);
    if(*num1>*num3) swap(num1,num3);
    if(*num2>*num3) swap(num2,num3);
}
int main()
{
	int A, B, C;
    scanf("%d %d %d",&A,&B,&C);
    sort(&A,&B,&C);
    printf("%d %d %d\n",A,B,C);
	system("pause");
	return 0;
}
