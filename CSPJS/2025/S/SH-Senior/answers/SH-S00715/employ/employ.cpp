#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mod 998244353
bool use[510],s[510];
int p[510],c[510],n,m;
bool solve()
{
	int now = 0,cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(!s[i] || cnt >= c[p[i]]) cnt++;
		else now++;
	}
//	cout << now << endl;
	return (now >= m);
}
int dfs(int x)
{
	if(x > n) return solve();
	else
	{
		int ans = 0;
		for(int i = 1;i <= n;i++) if(!use[i])
		{
			use[i] = true;
			p[i] = x;
			ans += dfs(x + 1);
			use[i] = false;
		}
		return ans;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		char kkk;
		cin >> kkk;
		s[i] = (kkk == '1');
	}
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(n <= 10) cout << dfs(1) << endl;
	else
	{
		int num = 0;
		for(int i = 1;i <= n;i++) if(c[i]) num++;
		if(num < m) cout << 0 << endl;
		else
		{
			int ans = 1;
			for(int i = 1;i <= num;i++) (ans *= i) %= mod;
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
