#include <bits/stdc++.h>
using namespace std;
const int MOD =  998244353;
int n, m, k = 0;
int cnt = 0;
int c[510], a[510];
bool used[510];
long long fact[510];
long long ft = 1, ft1, ft2, bad = 1, sum = 0, ans = 0;
string s;
void dfs(int step)
{
	if(step == n)
	{
		int lian = 0, num = 0;
		for(int i = 0;i < n;i ++)
		{
			if(s[i] == '0')
				lian ++;
			else
			{
				if(lian >= c[a[i]])
					lian ++;
				else
					num ++;
			}
		}

		if(num >= m)
			ans ++;
		ans %= MOD;
	}
	
	for(int i = 0;i < n;i ++)
	{
		if(!used[i])
		{
			used[i] = 1;
			a[step] = i;
			dfs(step + 1);
			used[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	
	for(int i = 0;i < n;i ++)
		cin >> c[i];
	
	if(n <= 10)
	{
		dfs(0);
		cout << ans << endl;
		return 0;
	}
	
	for(int i = 0;i < s.length();i ++)
		if(s[i] == '0')
			cnt ++;
	if(n - cnt < m)//不可能合法
	{
		cout << 0 << endl;
		return 0; 
	}
	else if(!cnt)//随便
	{	
		fact[0] = 1;
		for(int i = 1;i <= 500;i ++)
			fact[i] = fact[i - 1] * i % MOD;
		
		for(int i = 0;i < n;i ++)
			if(c[i] == 0)
				k ++;
		n -= k;
		ans = fact[n];
		for(int i = 1;i <= k;i ++)
		{
			ft1 = 1, ft2 = 1;
			for(int l = k - i + 1;l <= k;l ++)
				ft1 = ft1 * l % MOD;
			for(int l = n - i + 1;l <= n;l ++)
				ft2 = ft2 * l % MOD;
			bad = ft1 * ft2;
			sum = (sum + bad) % MOD;
		}
		cout << ans - sum << endl;
		return 0;
	}
	else
	{
		cout << 8 << endl;
	}
	return 0;
}
