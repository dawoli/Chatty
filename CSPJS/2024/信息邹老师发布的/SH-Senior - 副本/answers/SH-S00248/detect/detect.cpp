#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, m, L, V, p[100005], rec[100005], d, a, v, ans, tot;
pair <ll, ll> car[100005]; //exceed: [first, second]
bool check(ll num)
{
	ll sq = v * v + 2 * a * num;
	if (V * V >= sq) return 1;
	return 0;
}
vector <ll> vv[100005];
ll dm[100005];
bool bd[100005];
void dfs(ll now, ll cnt)
{
	if (now == m + 1)
	{
		for (ll i = 1; i <= n; i++)	if (bd[i] && dm[i] == 0) return;
		tot = max(tot, m - cnt);
		return;
	}
	for (ll i : vv[now]) dm[i]++;
	dfs(now + 1, cnt + 1);
	for (ll i : vv[now]) dm[i]--;
	dfs(now + 1, cnt);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> L >> V;
		ans = tot = 0;
		for (ll i = 1; i <= n; i++)
		{
			bd[i] = 0;
			cin >> d >> v >> a;
			if (a <= 0)
			{
				if (v <= V) car[i].first = car[i].second = L + 1;
				else
				{
					ll l = 0, r = L - d + 1;
					while (l < r)
					{
						ll mid = (l + r) / 2;
						if (!check(mid)) l = mid + 1;
						else r = mid;
					}
					car[i].first = d, car[i].second = l + d - 1;
				}
			}
			else
			{
				ll l = 0, r = L - d + 1;
				while (l < r)
				{
					ll mid = (l + r) / 2;
					if (check(mid)) l = mid + 1;
					else r = mid;
				}
				car[i].first = l + d, car[i].second = L;
			}
		}
		for (ll i = 1; i <= m; i++) cin >> p[i], vv[i].clear();
		for (ll i = 1; i <= n; i++)
		{
			ll l = lower_bound(p + 1, p + m + 1, car[i].first) - p;
			ll r = upper_bound(p + 1, p + m + 1, car[i].second) - p - 1;
			if (r - l + 1)
			{
				ans++;
				bd[i] = 1;
				for (ll j = l; j <= r; j++) vv[j].push_back(i);
			} 
		}
		dfs(1, 0);
		cout << ans << " " << tot << endl;
	}
} 
