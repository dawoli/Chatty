#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
考虑部分分：
对于所有性质Ａ：不需要花钱 
１～４：因为没有城镇，跑一个最小生成树结束
７～８，１１～１２，１５～１６，１９～２０：硬枚举＋最小生成树
也就是说，不能做的有：１５～１６　以及　２１～２５ 
 */

const int N = 1e4 + 5, M = 1e6 + 5, K = 10 + 5;

struct Node
{
	int u, v, w;
} e[2 * M], e2[2 * M];

bool flag = false;
int n, m, k, ans = 1e18, cnt, fa[2 * N], c[K], way[K], a[K][N];

bool cmp (Node xx, Node yy)
{
	return xx.w < yy.w;
}

int find (int x)
{
	if (fa[x] == x)	return x;
	else	return fa[x] = find(fa[x]);
}

int Kruskal()
{
	int ret = 0; cnt = 0;
	for (int i = 1; i <= 2 * n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)	
	{
		cnt++;
		e2[i] = e[i];
	}
	for (int i = 1; i <= k; i++)
	{
		if (!way[i])	continue;
		ret += c[i];
		for (int j = 1; j <= n; j++)
			e2[++cnt] = {n + i, j, a[i][j]};
	}
	sort (e2 + 1, e2 + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
	{
		int u = e2[i].u, v = e2[i].v, w = e2[i].w;
		if (find(u) == find(v))	continue;
		ret += w;
		fa[find(u)] = find(v);
	}
	return ret;
}

void dfs (int step)
{
	if (step > k)
	{
		ans = min(ans, Kruskal());
		return;
	}
	way[step] = true;
	dfs (step + 1);
	way[step] = false;
	dfs (step + 1);
}

signed main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++)
	{
		bool flg = true;
		cin >> c[i];
		if (c[i] != 0)	flg = false;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 0)	flg = false;
		}
		if (flg)	flag = true;
	}
	if (flag)
	{
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}

// 18 : 10 打了暴力，正确性应该问题不大，但是时间复杂度特别高 
