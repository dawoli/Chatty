#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >>n;
	if(n==1)
	{
		cout <<51;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin >>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			ans++;
			continue;
		}
		if(s[i]!=s[i-1])
		{
			ans++;
		}
	}
	ans=52-ans;
	cout <<ans;
	return 0;
}
