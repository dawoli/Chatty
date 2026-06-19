#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, a[15][10005], c[15], f[1000005], ans, cnt, vst[15];
priority_queue<pair<int, pair<int, pair<int, int> > > > q;
int find(int x)
{
	if(x == f[x]) return x;
	else return f[x] = find(f[x]); 
}
bool merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx != fy) 
	{
		f[fx] = fy;
		return 1;
	}
	return 0;
}
signed main()
{
//	freopen("road1.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++) f[i] = i;
	
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		q.push({-w, {0, {u, v}}});
	}
	for(int i = 1; i <= k; i++)
	{
		cin>>c[i];
		for(int j = 1; j <= n; j++) cin>>a[i][j];
	}
	
	for(int d = 1; d <= k; d++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				q.push({-(a[d][i] + a[d][j]), {d, {i, j}}});
			}
		}
	}
	while(!q.empty())
	{
		int now = -q.top().first;
		int u = q.top().second.second.first, v = q.top().second.second.second, vi = q.top().second.first;
		if(!vst[vi]) vst[vi] = 1, ans += c[vi]; // not true sometimes
		q.pop();
		if(merge(u, v))
		{
			ans += now; 
			cnt++;
			if(cnt == n - 1)
			{
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	return 0;	
} 
