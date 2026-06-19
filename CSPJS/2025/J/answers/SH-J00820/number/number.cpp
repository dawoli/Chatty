#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int num[1000001],cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for (int i=cnt;i>=1;i--)
	{
		cout<<num[i];
	}
}
