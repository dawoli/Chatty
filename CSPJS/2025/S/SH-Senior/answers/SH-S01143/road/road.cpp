/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, m, k, first[N], idx, fa[N], link[N], cnt1, ans1, cnt2, ans2;
/*struct edge{
	int v, next, w;
}e[N * 2];*/
struct node{
	int u,v, w;
}a[2 * N];
/*void add_edge(int u, int v, int w)
{
	idx++;
	e[idx].v = v;
	e[idx].next = first[u];
	e[idx].w = w;
	first[u] = idx;
}*/
bool cmp(node a, node b)
{
	return a.w < b.w;
}
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]); 
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n + k; ++i)
	{
		fa[i] = i;
	}
	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= m; ++i)
	{
		int fx = find(a[i].u), fy = find(a[i].v);
		if(fx == fa[fy]) fa[fy] = fx; 
		cout << fx << " " << fy << " " << fa[fx] << " " << fa[fy] << '\n';
		if(cnt1 != n - 1)
		{
			cnt1++;
			ans1 += a[i].w;
		}
	}
	for(int i = 1; i <= k; ++i)
	{
		long long c;
		cin >> c;
		a[m + i].u = n + i, a[m + i].v = n + i, a[m + i].w = c; 
		for(int j = 1; j <= n; ++j)
		{
			int tmp = 1;
			cin >> link[j];
			a[m + k + tmp * j].u = n + i, a[m + k + tmp * j].v = i, a[m + k + tmp * j].w = link[j];
			tmp++;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= m +k + k * n; ++i)
	{
		int fx1 = find(a[i].u), fy1 = find(a[i].v);
		if(fx1 == fa[fy1]) fa[fy1] = fx1;
		
		cout << fx1 << " " << fy1 << " " << fa[fx1] << " " << fa[fy1] << '\n';
		if(cnt2 != n - 1)
		{
			cnt2++;
			ans2 += a[i].w;
		}
	}
	cout << ans1 <<" " << ans2;
	
	return 0;
}
