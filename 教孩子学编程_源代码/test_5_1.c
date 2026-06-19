#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
    char ch1, ch2, ch3;
    printf("请输入一个字符：");
    scanf("%c",&ch1);
    n = ch1;  
    ch2 = ch1-1;
    ch3 = ch1+1;
	printf("十进制序号：%d\n",n);
	printf("字符：%c\n",ch1);
	printf("前一个字符：%c\n",ch2);
	printf("后一个字符：%c\n",ch3);
	//printf("序号 字符 前一个字符 后一个字符\n");
	//printf("%4d %3c %6c %10c\n",n,ch1,ch2,ch3);
	system("pause");
	return 0;
}
