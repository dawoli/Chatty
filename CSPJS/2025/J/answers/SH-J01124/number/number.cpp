#include <cstdio>
#include <cstring>
char str[1001000];
int tong[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			tong[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=tong[i];j++)
		{
			putchar(i+'0');
		}
	}
	printf("\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
