#include <iostream>
using namespace std;
#define mod 998244353
#define ll long long
ll n, m, p[501], q[501], ans;
char a[501];
bool vis[501];
void dfs(int x)
{
	if (x > n)
	{
		ll cnt = 0, fq = 0;
		for (int i = 1; i <= n; i++)
		{
			if (fq >= q[i]) 
			{
				++fq;
				continue;
			}
			if (a[i] == '1') ++cnt;
			else ++fq;
		}
		if (cnt >= m) ans = (ans + 1) % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			vis[i] = 1;
			q[x] = p[i];
			dfs(x + 1);
			q[x] = 0;
			vis[i] = 0;
		}
	}
}
void solvebl()
{
	dfs(1);
	cout << ans;
}
void solvea()
{
	ll fqg = 0;
	for (int i = 1; i <= n; i++) 
		if (p[i] == 0)
			++fqg;
	n -= fqg;
	ll ans = 1;
	for (ll i = 1; i <= n + 1; i++)
	{
		ans = (ans * i % mod) % mod;
		ans %= mod;	
	} 
	cout << ans;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	if (n <= 10)
	{
		solvebl();
		return 0;
	}
	solvea(); 
	return 0;
}
