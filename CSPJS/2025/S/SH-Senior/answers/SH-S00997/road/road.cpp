#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt;
int f[10005], c[15], a[15][10005];
struct node
{
	int u, v, w;
} r[2000005];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
int fa(int t)
{
	int x = t;
	while(f[x] != x) x = f[x];
	return f[x];
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	bool fl = false;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i] != 0) fl = true;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	sort(r+1, r+m+1, cmp);
	if(k == 0)
	{
		int num = 0;
		for(int i = 1; i <= m; i++)
		{
			if(fa(r[i].u) != fa(r[i].v))
			{
				num++;
				cnt+=r[i].w;
				f[fa(r[i].u)] = fa(r[i].v);
			}
		}
		cout << cnt << endl;
		return 0;
	}
	if(fl==false)
	{
		for(int i = 1; i <= k; i++)
		{
			int h;
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] == 0) h = j;
			}
			for(int j = 1; j <= m+n; j++)
			{
				if(h == j) continue;
				m++;
				r[m].u = h, r[m].v = j, r[m].w = a[h][j];
			}
		}
		sort(r+1, r+m+1, cmp);
		int num = 0;
		for(int i = 1; i <= m; i++)
		{
			if(fa(r[i].u) != fa(r[i].v))
			{
				num++;
				cnt+=r[i].w;
				f[fa(r[i].u)] = r[i].v;
			}
		}
		cout << cnt << endl;
		return 0;
	}
	return 0;
}
