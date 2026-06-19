#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, k, q, p, a[200005], r, c;
vector <pair <ll, ll> > e[200005];
struct st
{
	ll now, pos, len;
}tmp;
queue <st> qq;
unordered_set <ll> ss;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> q;
		for (ll i = 1; i <= 200000; i++) e[i].clear();
		for (ll i = 1; i <= n; i++)
		{
			cin >> p;
			for (ll j = 1; j <= p; j++) cin >> a[j];
			ss.clear();
			for (ll j = 1; j <= p; j++)
			{
				for (ll o = j + 1; o <= min(p, j + k - 1); o++)
				{
					if (ss.count(a[j] * 200000 + a[o])) continue;
					e[a[j]].push_back({a[o], i});
					ss.insert(a[j] * 200000 + a[o]);
				}
			} 
		}
		while (q--)
		{
			cin >> r >> c;
			while (qq.size()) qq.pop();
			qq.push({1, 0, 0});
			while (qq.size())
			{
				tmp = qq.front();
				qq.pop();
				if (tmp.len == r)
				{
					if (tmp.now == c)
					{
						cout << 1 << endl;
						goto here;
					}
					else continue;
				}
				for (pair <ll, ll> i : e[tmp.now])
				{
					if (i.second == tmp.pos) continue;
					qq.push({i.first, i.second, tmp.len + 1});
				}
			}
			cout << 0 << endl;
			here:;
		}
	}
} 
