#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node
{
	long long l, r, id;
	bool operator < (const node a) const
	{
		return l > a.l; 
	}
} c[N];
struct tail
{
	long long l, r, id;
	bool operator < (const tail a) const
	{
		return r > a.r;
	}
};
priority_queue <node> lq;
priority_queue <tail> rq;
int n, m, tot, ans, pt;
long long L, V, t, d, v, a, p[N];
bool vis[N];
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		tot = 0;
		ans = 0;
		pt = 0;
		scanf("%d%d%lld%lld", &n, &m, &L, &V);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &d, &v, &a);
			if (a < 0)
			{
				if (v <= V)
				{
					c[i].r = -1;
					continue;
				}
				c[i].l = d, c[i].r = (V * V - v * v) / 2 / a + d;
				if (c[i].r > L) c[i].r = L;
			}
			else if (a == 0)
			{
				if (v <= V)
				{
					c[i].r = -1;
					continue;
				}
				c[i].l = d, c[i].r = L;
			}
			else
			{
				if (v + (L - d) * a <= V)
				{
					c[i].r = -1;
					continue;
				}
				if (v > V)
				{
					c[i].l = d, c[i].r = L;
				}
				else
					c[i].l = (V * V - v * v) / 2 / a + d, c[i].r = L;
			}
			c[i].id = i;
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%lld", &p[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (c[i].r == -1)
			{
				continue;
			}
			if ((*lower_bound(p + 1, p + m + 1, c[i].l)) <= c[i].r)
			{
				tot++;
				lq.push(c[i]);
				rq.push(tail{c[i].l, c[i].r, c[i].id});
			}
			else c[i].r = -1;
		}
		printf("%d ", tot);
		while (!rq.empty())
		{
			if (vis[rq.top().id])
			{
				rq.pop();
				continue;
			}
			while (pt < m && p[pt + 1] <= rq.top().r)
			{
				pt++;
			}
			while (!lq.empty() && lq.top().l <= p[pt])
			{
				vis[lq.top().id] = true;
				lq.pop();
			}
			ans++; 
			rq.pop();
		}
		printf("%d\n", m - ans);
	}
}
