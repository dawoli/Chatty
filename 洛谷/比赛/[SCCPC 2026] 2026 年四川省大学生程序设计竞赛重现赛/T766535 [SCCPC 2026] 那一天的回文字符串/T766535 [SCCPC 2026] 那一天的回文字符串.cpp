// Problem URL: https://www.luogu.com.cn/problem/T766535?contestId=330334
// Finish Time: 2026/6/21 14:41:53 AC
// Start Time: 2026/6/21 14:17:02

#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	vector<int> odd(26,0),even(26,0);
	for(int i=0; i<n; ++i)
	{
		if((i+1)%2==0)
			even[s[i]-'a']++;
		else
			odd[s[i]-'a']++;
	}
	if(n%2==0)
	{
		bool ok=true;
		for(int i=0; i<26; ++i)
		{
			if(odd[i]!=even[i])
			{
				ok=false;
				break;
			}
		}
		cout<<(ok?"YES":"NO")<<'\n';
	}
	else
	{
		int odd_odd=0,even_odd=0;
		for(int i=0; i<26; ++i)
		{
			if(odd[i]%2!=0) odd_odd++;
			if(even[i]%2!=0) even_odd++;
		}
		int odd_len=(n+1)/2;
		if(odd_len%2==1)
		{
			cout<<(odd_odd<=1&&even_odd==0?"YES":"NO")<<'\n';
		}
		else
		{
			cout<<(even_odd<=1&&odd_odd==0?"YES":"NO")<<'\n';
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}