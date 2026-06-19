#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll cnt,num[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9') num[++cnt]=s[i]-'0';
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		printf("%lld",num[i]);
	}
	return 0;
 } 
