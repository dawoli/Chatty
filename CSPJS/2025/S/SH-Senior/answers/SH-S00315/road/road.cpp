#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3000205, M = 10005, K = 12, INF = 1e18 + 9;

struct edge
{
	int u, v, w, pos;
	bool operator <(const edge &e) const
	{
		return w < e.w;
	}
}e1[N], e[N];

int p[N], a[K][M];
int n, m, k, tp, pos;
int num;

int find(int x)
{
	if (x == p[x]) return x;
	else return p[x] = find(p[x]); 
}

int find_tree()
{
	int sum = 0;
	for (int i = 1, cnt = 1; i <= pos && cnt < num; ++ i)
	{
		if(find(e[i].u) == find(e[i].v)) continue;
		p[find(e[i].u)] = find(e[i].v), sum += e[i].w, cnt ++;
	}
	return sum;
}

void solve_A()
{
	int tmp = 0; num = n;
	for (int j = 1; j <= tp; ++ j) e[j] = e1[j];
	pos = tp;
	for (int j = 0; j < k; ++ j)
	{
		num ++;
		for (int l = 1; l <= n; ++ l)
			e[++ pos] = (edge) {n + j + 1, l, a[j][l], pos};
	}
	for (int j = 0; j <= num + 1; ++ j) p[j] = j;
	sort(e + 1, e + pos + 1);
	int ans = 0;
	for (int i = 1, cnt = 1; i <= pos && cnt < num; ++ i)
	{
		if(find(e[i].u) == find(e[i].v)) continue;
		p[find(e[i].u)] = find(e[i].v), ans += e[i].w, cnt ++;
	}
	cout << ans << endl;
}

void solve_BF()
{
	cin >> n >> m >> k;
	
	for (int i = 1, u, v, w; i <= m; ++ i)
	{
		cin >> u >> v >> w;
		e1[++ tp] = (edge) {u, v, w, i};
	}
	
	int yyy = 0;
	for (int i = 0; i < k; ++ i)
		for (int j = 0; j <= n; ++ j)
		{
			cin >> a[i][j];
			if (j == 0 && a[i][0] == 0) yyy ++;
		}
	
	if (yyy == k)	{ solve_A(); return; }
	
	int ans = INF;
	for (int i = 0; i < (1 << k); ++ i)
	{
		int tmp = 0;
		num = n;//tree_sz;
		for (int j = 1; j <= tp; ++ j) e[j] = e1[j];
		pos = tp;
		for (int j = 0; j < k; ++ j)
			if ((1 << j) & i)
			{
				num ++; tmp += a[j][0];
				for (int l = 1; l <= n; ++ l)
					e[++ pos] = (edge) {n + j + 1, l, a[j][l], pos};
			}
		for (int j = 0; j <= num + 1; ++ j) p[j] = j;
		sort(e + 1, e + pos + 1);
		tmp += find_tree();
		ans = min(ans, tmp);
	}
	cout << ans << endl;
} 

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	solve_BF();
	
	return 0;
 } 
