#include<bits/stdc++.h>

using namespace std;

int n;

string s[55];

map<string,int>mp;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>s[i];
		mp[s[i]]++;
	}
	int ans = 52-n;
	for(int i = 1;i <= n;i++)
	{
		if(mp[s[i]] > 1)
		{
			ans++;
			mp[s[i]]--;
		}
	}
	cout<<ans;
	return 0;
} 
