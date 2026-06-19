#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map <string,ll> mp;
char c[4] = {'D','C','H','S'};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i = 1;i <= n;i++)
	{
		string s;
		cin>>s;
		mp[s] = 1;
	}
	ll ans = 0;
	for(ll i = 1;i <= 4;i++)
	{
		for(ll j = 1;j <= 13;j++)
		{
			string word;
			word += c[i - 1];
			if(j == 1) word += 'A';
			else if(j == 10) word += 'T';
			else if(j == 11) word += 'J';
			else if(j == 12) word += 'Q';
			else if(j == 13) word += 'K';
			else word += char('1' + j - 1);
			if(!mp[word]) ans += 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
