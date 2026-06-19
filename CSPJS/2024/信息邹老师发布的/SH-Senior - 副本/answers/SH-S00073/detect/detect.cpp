#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, L, V, d[N], v[N], a[N], p[N], cnt = 0, cnt2 = 0, s[N];
bool vis[N];
bool cmp(int i, int j)
{
	return 1ll * (v[i] * v[i]) + 2ll * a[i] * (p[j] - d[i]) > 1ll * V * V;
}
bool check()
{
	for (int i = 1; i <= cnt; i++)
	{
		bool flag = false;
		for (int j = 1; j <= m; j++)
		{
			if (cmp(s[i], j) && d[s[i]] <= p[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false) return false;
	}
	return true;
}
void dfs(int p, int cnt)
{
	if (n - p + 1 + cnt <= cnt2) return ;
	if (check() == false) return ;
	if (p > m)
	{
		cnt2 = max(cnt2, cnt);
		return ;
	}
	vis[p] = true;
	dfs(p + 1, cnt);
	vis[p] = false;
	if (check() == false) return ;
	dfs(p + 1, cnt + 1); 
}
void solve()
{
	cnt = cnt2 = 0;
	memset(vis, true, sizeof(vis));
	memset(d, 0, sizeof(d));
	memset(v, 0, sizeof(v));
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	memset(s, 0, sizeof(s));
	scanf("%d%d%d%d", &n, &m, &L, &V);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &d[i], &v[i], &a[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cmp(i, j) && d[i] <= p[j])
			{
				s[++cnt] = i;
				break;
			}
		}
	}
	printf("%d ", cnt);
	dfs(1, 0);
	printf("%d\n", cnt2);	
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
