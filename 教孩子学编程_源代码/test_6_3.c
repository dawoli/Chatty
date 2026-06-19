#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch1,ch2;
    int tmp;
    ch1 = getchar();  ch2 = getchar();
    if((ch1-ch2) == 1) tmp = 1;
    else tmp = -1;
    printf("%c%c\n",ch1+tmp,ch2+tmp);
	system("pause");
	return 0;
}
