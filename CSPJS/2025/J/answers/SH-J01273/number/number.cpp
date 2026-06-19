#include<bits/stdc++.h>
using namespace std;
char s[1000011];
int f[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')f[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=f[i];j++)printf("%c",char('0'+i));
	}
	printf("\n");
	return 0;
}
