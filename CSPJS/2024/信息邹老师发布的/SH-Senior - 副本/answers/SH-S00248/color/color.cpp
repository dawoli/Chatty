#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, a[200005], ans;
bool b[200005];
void dfs(ll now)
{
	if (now == n + 1)
	{
		ll lst[2] = {0, 0}, tot = 0;
		for (ll i = 1; i <= n; i++)
		{
			tot += (a[lst[b[i]]] == a[i]) * a[i];
			lst[b[i]] = i;
		}
		ans = max(ans, tot);
		return;
	}
	b[now] = 0;
	dfs(now + 1);
	b[now] = 1;
	dfs(now + 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		for (ll i = 1; i <= n; i++) cin >> a[i];
		dfs(1);
		cout << ans << endl;
	}
}
