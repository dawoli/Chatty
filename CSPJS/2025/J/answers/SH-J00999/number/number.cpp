#include <bits/stdc++.h>
using namespace std;
int cnt[1000010];
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int tot=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[tot]=s[i]-'0';
			tot++;
		}
	}
	sort(cnt,cnt+tot);
	for(int i=tot-1;i>=0;i--)
	{
		printf("%d",cnt[i]);
	}
	return 0;
}
