#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int n, m, c[500];
string s;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	bool flag1 = 1;
	for(int i = 1; i <= n; i++) 
	{
		if(s[i] == '0') flag1 = 0; 
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) 
	{
		cin>>c[i];
		if(c[i] == 0) cnt++;
	}
	if(flag1)
	{
		n -= cnt;
		int ans = 1;
		for(int i = 1; i <= n; i++)
		{
			ans = ans * i % MOD; 
		}
		cout<<ans * (cnt + 1) % MOD<<endl;
	}
	return 0;
}
