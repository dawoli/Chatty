#include<bits/stdc++.h>
using namespace std;

const int _ = 3e6 + 9;
struct line{
	int u, v, w;
}a[_];
bool cmp(line x, line y)
{
	return x.w < y.w;
}
int n, m, k, cnt, oknum, ans, ok[20], vis[_];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while(m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[++cnt] = { u, v, w };
	}
	for(int i = 1;i <= k;i++)
	{
		int c;
		cin >> c;
		a[++cnt] = { 0, n + i, c };
		for(int j = 1;j <= n;j++)
		{
			int w;
			cin >> w;
			a[++cnt] = { j, n + i, w };
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1;i <= cnt;i++)
	{
		if(oknum >= n)
			break;
		if(!vis[a[i].u] || !vis[a[i].v])
		{
			if((a[i].u > n && !ok[a[i].u - n] && a[i].v) || (a[i].v > n && !ok[a[i].v - n] && a[i].u))
				continue;
			if(!vis[a[i].u] && a[i].u >= 1 && a[i].u <= n)
				oknum++;
			if(!vis[a[i].v] && a[i].v >= 1 && a[i].v <= n)
				oknum++;
			if(a[i].u > n)
				ok[a[i].u - n] = 1;
			if(a[i].v > n)
				ok[a[i].v - n] = 1;
			vis[a[i].u] = vis[a[i].v] = 1, ans += a[i].w;
			cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << '\n';
		}
	}
	cout << ans;
	
	return 0;
}
