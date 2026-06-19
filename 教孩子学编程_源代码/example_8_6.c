#include <stdio.h>
#include <stdlib.h>

int fx=0;

void func(void)
{
	static int sx=0;
    int ax=0;
    printf("%3d %3d %3d\n",ax++,sx++,fx++);
}

int main()
{
	system("color 70");
    int i;
    printf("  i  ax  sx  fx\n");
    printf("----------------\n");
    for(i=0;i<10;i++)
    {
		printf("%3d ",i);
        func();
    }
    printf("----------------\n");
	system("pause");
	return 0;
}
