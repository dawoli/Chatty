#include <bits/stdc++.h>
using namespace std;

string s,ans;
int cnt[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.length();++i)
	{
		if(isdigit(s[i]))
		{
			++cnt[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;--i)
	{
		while(cnt[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
