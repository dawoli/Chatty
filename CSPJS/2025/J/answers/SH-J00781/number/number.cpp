#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int a[1000005],n=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}
