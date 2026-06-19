#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int u[1000005], v[1000005], w[1000005];
int c[15];
int a[15][10005];
bool choice[15];
long long summ = 0;
struct Edge
{
	int u, v, w;
	bool operator < (const Edge &x) const
	{
		return w < x.w;
	}
};

int fa[20000];
set<Edge> s;

int findset(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = findset(fa[x]);
}

bool Same(int x, int y)
{
	int fx = findset(x), fy = findset(y);
	if (fx == fy)
		return true;
	return false;
}

void Union(int x, int y)
{
	int fx = findset(x), fy = findset(y);
	fa[fx] = fy;
}

void shortest_tree()
{
	s.clear();
	for (int i = 1; i <= m; i++)
	{
		s.insert(Edge{u[i], v[i], w[i]});
		s.insert(Edge{v[i], u[i], w[i]});
	}
	for (int i = 1; i <= k; i++)
	{
		if (!choice[i]) continue;
		for (int j = 1; j <= n; j++)
		{
			s.insert(Edge{n + i, j, a[i][j]});
			s.insert(Edge{j, n + i, a[i][j]});
		}
	}
	for (int i = 1; i <= n + k; i++)
	{
		fa[i] = i;
	}
	while (!s.empty())
	{
		Edge x = *s.begin();
		s.erase(s.begin());
		if (!Same(x.u, x.v))
		{
			summ += x.w;
			Union(x.u, x.v);
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	long long ans = 1ll << 60;
	for (int i = 0; i < (1 << k); i++)
	{
		summ = 0;
		for (int j = 0; j < k; j++)
		{
			if (i & (1 << j))
			{
				choice[j + 1] = true;
				summ += c[j + 1];
			}
			else
			{
				choice[j + 1] = false;
			}
		}
		shortest_tree();
		ans = min(ans, summ);
	}
	printf("%lld\n", ans);
	return 0;
}
