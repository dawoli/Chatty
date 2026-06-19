#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
struct rd{
	int x, y;
	int val;
}c[1000005];
bool cmp(rd aa, rd bb)
{
	return aa.val > bb.val;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int deg[10005];
	memset(deg,0,sizeof(deg));
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		deg[u]++;
		deg[v]++;
		c[i].x = u;
		c[i].y = v;
		c[i].val = w;
		ans+=w;
	}
	sort(c+1,c+m+1,cmp);
	int b = m, pk = 1;
	while (b > n-1)
	{
		rd l = c[pk];
		if (deg[l.x] > 1 && deg[l.y > 1])
		{
			ans-=l.val;
			deg[l.x]--;
			deg[l.y]--;
			b--;
		}
		pk++;
	}
	cout << ans;
	return 0;
}
