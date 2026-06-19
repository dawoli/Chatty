#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p, *q, a, b;
    p = &a; q = &b;
    *p = 10;
    *q = 3;
    *q *= *p;
    printf("step1£ºa=%d *p=%d\n", a, *p);
    printf("step1£ºb=%d *q=%d\n", b, *q);
    *p = 200;
    q = p;
    printf("step2£ºa=%d *p=%d\n", a, *p);
    printf("step2£ºb=%d *q=%d\n", b, *q);
	system("pause");
	return 0;
}
