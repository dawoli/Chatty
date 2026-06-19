#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int NR = 1e4+5, MR = 1e6+1e5+5;
int n, m, k, c[NR], a[15][NR];
struct node{int u, v, w;};
node edge[MR];

int f[NR];
int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void merge(int x, int y)
{
	f[find(x)] = find(y);
}

bool cmp(node x, node y)
{
	return x.w < y.w;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld%lld%lld", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	int cur = m;
	for(int i = 1; i <= k; i++)
	{
		int p = 0;
		for(int j = 1; j <= n; j++)
		{
			if(a[i][j] == 0)
			{
				p = j;
				break;
			}
		}
		for(int v = 1; v <= n; v++)
		{
			if(v == p) continue;
			edge[++cur] = (node){v, p, a[i][v]};
		}
	}
	sort(edge+1, edge+cur+1, cmp);
	int ans = 0;
	for(int i = 1; i <= cur; i++)
	{
		if(find(edge[i].u) == find(edge[i].v)) continue;
		merge(edge[i].u, edge[i].v);
		ans += edge[i].w;
	}
	printf("%lld\n", ans);
	return 0;
}
