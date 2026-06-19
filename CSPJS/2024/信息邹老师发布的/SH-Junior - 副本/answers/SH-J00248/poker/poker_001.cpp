#include <bits/stdc++.h>
using namespace std;
#define int long long
map <string,int> mp; 
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		if(!mp.count(s))
		{
			mp[s]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

