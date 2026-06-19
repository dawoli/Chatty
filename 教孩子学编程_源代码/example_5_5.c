#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("color 70");
	long days=24*60*60;
	long months=days*30;
	long years=months*12;
    long n,y,m,d,HH,MM,SS;
    printf("\n输入整数n（0-2147483647）：");
    scanf("%ld",&n);
    y = n/years+1970;
    m = n%years/months+1;
    d = n%years%months/days+1;
    HH = n%years%months%days/3600;
    MM = n%years%months%days%3600/60;
    SS = n%years%months%days%3600%60;
    printf("\n%d年%d月%d日%d时%d分%d秒\n\n",y,m,d,HH,MM,SS);
    system("pause");
    return 0;
}
