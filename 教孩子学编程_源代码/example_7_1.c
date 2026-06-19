#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch;
    int Letter=0,Digit=0;
    printf("输入一串‘？’结尾的字符：");
    ch=getchar();                   //循环外读入第一个字符
    while(ch!='?')
    {
		if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')))
			Letter++;                 //字母的个数加1
        else if((ch>='0')&&(ch<='9'))
			Digit++;                  //数字的个数加1
        ch=getchar();                 //继续读入下一个字符
    }
    printf("其中字母的个数是：%d\n",Letter);    
    printf("其中数字的个数是：%d\n",Digit);
	system("pause");
	return 0;
}
