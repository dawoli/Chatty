#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+10;
ll t, n, m, L, V, d[N], v[N], a[N], p[N], St[N], En[N], ans1, ans2;
bool vis[N], is_speed[N];
vector<ll> ST[N];
vector<ll> EN[N];
queue<ll> q;

ll small(ll x, ll y)
{
	ll l = 0, r = m + 1;
	while (l < r)
	{
		ll mid = (l + r + 1) >> 1;
		if (p[mid] * y > x)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	return l;
}

ll big(ll x, ll y)
{
	ll l = 0, r = m + 1;
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		if (p[mid] * y > x)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
		for (ll i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &d[i], &v[i], &a[i]);
			St[i] = 1e9;
			En[i] = -1e9;
			is_speed[i] = false;
		}
		for (ll i = 1; i <= m; i++)
		{
			scanf("%lld", &p[i]);
			vis[i] = false;
			ST[i].clear();
			EN[i].clear();
		}
		while (!q.empty()) q.pop();
		ans1 = ans2 = 0;
		p[0] = -1e9;
		p[m + 1] = 1e9;
		for (ll i = 1; i <= n; i++)
		{
			ll x = 2 * a[i] * d[i] + V * V - v[i] * v[i];
			//printf("id:%lld,speedpos:%lld/%lld\n", i, x, 2 * a[i]);
			if (a[i] >= 0)
			{
				/*
				for (ll j = m; j >= 1 && p[j] >= d[i]; j--)
				{
					if (2 * a[i] * p[j] <= x) 
					{
						break;
					}
					St[i] = min(St[i], j);
					En[i] = max(En[i], j);
					is_speed[i] = true;
					//printf("chaosu id:%lld, detector id:%lld\n", i, j);
				}
				*/
				
				St[i] = max(big(x, 2 * a[i]), lower_bound(p, p + m + 1, d[i]) - p);
				En[i] = m;
				if (St[i] <= m)
				{
					is_speed[i] = true;
					ans1++;
					ST[St[i]].push_back(i);
					EN[En[i]].push_back(i);
				}
				
			}
			else
			{
				/*
				for (ll j = 1; j <= m; j++)
				{
					if (p[j] >= d[i])
					{
						if (2 * a[i] * p[j] <= x) 
						{
							break;
						}
						St[i] = min(St[i], j);
						En[i] = max(En[i], j);
						is_speed[i] = true;
						//printf("chaosu id:%lld, detector id:%lld\n", i, j);
					}
				}
				*/
				
				St[i] = lower_bound(p, p + m + 1, d[i]) - p;
				En[i] = small(x, (2 * a[i]));
				if (St[i] >= 1 && En[i] <= m && St[i] <= En[i])
				{
					is_speed[i] = true;
					ans1++;
					ST[St[i]].push_back(i);
					EN[En[i]].push_back(i);
				}
				
			}
		}
		/*
		for (ll i = 1; i <= n; i++)
		{
			if (is_speed[i])
			{
				ans1++;
				//printf("st(%lld)=%lld,en(%lld)=%lld\n", i, St[i], i, En[i]);
				ST[St[i]].push_back(i);
				EN[En[i]].push_back(i);
			}
		}
		*/
		for (ll i = 1; i <= m; i++)
		{
			for (ll j = 0; j < ST[i].size(); j++)
			{
				q.push(ST[i][j]);
				//printf("push %lld\n", ST[i][j]);
			}
			for (ll j = 0; j < EN[i].size(); j++)
			{
				if (!vis[EN[i][j]])
				{
					ans2++;
					//printf("put detector %lld\n", i);
					while(!q.empty())
					{
						vis[q.front()] = true;
						//printf("vis %lld\n", q.front());
						q.pop();
					}
				}
			}
		}
		printf("%lld %lld\n", ans1, m - ans2);
	}
	return 0;
} 
