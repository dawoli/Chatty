#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
#define mod 998244353
using namespace std;
int n, m;
char s[505];
int c[505];
ll ans;
int used[505];
void dfs(int p, int d)
{
	if(p == n)
	{
		ans++, ans %= mod;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!used[i] && d < c[i])
			used[i] = p, dfs(p + 1, d + !bool(s[p + 1] - '0'));
		used[i] = 0;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(0, 0);
	cout << ans;
	return 0;
}

