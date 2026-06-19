#include <stdio.h>
#include <stdlib.h>
char upperToLower(char ch)
{
	return ch+32;
}
int main()
{
	char ch;
    printf("输入一行由大写字母组成的字符，并回车!\n");
    while ((ch = getchar()) != '\n')
		printf("%c",upperToLower(ch));
    printf("\n");
	system("pause");
	return 0;
}
