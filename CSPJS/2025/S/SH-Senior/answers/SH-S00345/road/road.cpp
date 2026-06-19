#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5, mod = 1e9 + 7;
struct node
{
	ll u, v, w;
};
struct Edge
{
	ll v, w;
};
ll n, m, k, u, v, w, c[N], a[15][N], pa[N], h[N], ans, now, ret;
bool flag;
vector<node> b, d;
vector<Edge> to[N];
bool cmp(node a, node b)
{
	return a.w < b.w;
}
ll find(ll x)
{
	if(pa[x] == x)
	{
		return x;
	}
	pa[x] = find(pa[x]);
	return pa[x];
}
void merge(ll x, ll y)
{
	x = find(x);
	y = find(y);
	if(h[x] == h[y])
	{
		pa[x] = y;
		h[y]++;
	}
	else if(h[x] > h[y])
	{
		pa[y] = x;
	}
	else
	{
		pa[x] = y;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> u >> v >> w;
		b.push_back({u, v, w});
	}
	for(int i = 1; i <= n + 20; i++)
	{
		h[i] = 1;
		pa[i] = i;
	}
	sort(b.begin(), b.end(), cmp);
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i] != 0)
		{
			flag = 1;
		}
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] != 0)
			{
				flag = 1;
			}
		}
	}
	if(!flag && k != 0)
	{
		cout << 0;
		return 0;
	}
	for(auto i : b)
	{
		if(find(i.u) != find(i.v))
		{
			ans += i.w;
			merge(i.u, i.v);
		}
	}
	if(k == 0)
	{
		cout << ans;
		return 0;
	}
	for(int i = 1; i < (1 << k); i++)
	{
		for(int j = 1; j <= n + 20; j++)
		{
			h[j] = 1;
			pa[j] = j;
		}
		d.clear();
		now = ret = 0;
		for(auto j : b)
		{
			d.push_back(j);
		}
		ll tmp = i;
		while(tmp)
		{
			now++;
			if(tmp % 2 == 1)
			{
				for(int j = 1; j <= n; j++)
				{
					d.push_back({n + now, j, a[now][j]});
				}
				ret += c[now];
			}
			tmp /= 2;
		}
		sort(d.begin(), d.end(), cmp);
		for(auto j : d)
		{
			if(find(j.u) != find(j.v))
			{
				ret += j.w;
				merge(j.u, j.v);
			}
		}
		ans = min(ans, ret);
	}
	cout << ans;
	return 0;
}
