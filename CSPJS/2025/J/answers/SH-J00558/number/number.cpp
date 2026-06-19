#include<bits/stdc++.h>
using namespace std;

char s[1000010]={0};
int cnt[15]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int i=0;
	while(s[i]!=0)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]-'0']++;
		}
		i++;
	}
	for(i=9;i>=0;i--)
	{
		while(cnt[i])
		{
			printf("%d",i);
			cnt[i]--;
		}
	}
	
	return 0;
}
