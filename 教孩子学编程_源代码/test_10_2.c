#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *s = "I love China";
    int i;
    for(i=0;i<12;i++)
		printf("%s\n", &s[i]);
    while (*s) {
		printf("%c", *s);
        s++;
    }
    printf("\n");
	system("pause");
	return 0;
}
