#include <bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>=48&&s[i]<=58)
		{
			int x=s[i];
			a[x-48]++;
		}
	}
	int ans=0;
	for (int i=9;i>=0;i--)
	{
		while (a[i])
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
