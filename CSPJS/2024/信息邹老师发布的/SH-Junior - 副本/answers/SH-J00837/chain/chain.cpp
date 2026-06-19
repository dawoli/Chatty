#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
const int V = 2e5;
int n,k,q,l,s[N],r[N],c[N],maxstep,f[N][109];
vector<int> to[N],w[N];
void addedge(int u, int v, int c)
{
	to[u].push_back(v);
	w[u].push_back(c);
}
void dfs(int u, int step, int pre)
{
	if (f[u][step] == -1 || f[u][step] == pre) return;
	if (!f[u][step])
	{
		f[u][step] = pre;
		if (step == maxstep) return;
		for (int i = 0; i < to[u].size(); ++i)
		{
			int v = to[u][i],c = w[u][i];
			if (c == pre) continue;
			dfs(v, step + 1, c);
		}
	}
	else
	{
		if (step == maxstep)
		{
			f[u][step] = -1;
			return;
		}
		for (int i = 0; i < to[u].size(); ++i)
		{
			int v = to[u][i],c = w[u][i];
			if (c != f[u][step]) continue;
			dfs(v, step + 1, c);
		}
		f[u][step] = -1;
	}
}
void solveBF()
{
	scanf("%d%d%d", &n, &k, &q);
	for (int m = 1; m <= n; ++m)
	{
		scanf("%d", &l);
		for (int i = 1; i <= l; ++i) scanf("%d", &s[i]);
		for (int i = 1; i <= l; ++i)
			for (int j = i + 1; j <= l && j <= i + k - 1; ++j)
				addedge(s[i], s[j], m);
	}
	for (int i = 1; i <= q; ++i) scanf("%d%d", &r[i], &c[i]);
	maxstep = *max_element(r + 1, r + q + 1);
	dfs(1, 0, -1);
	for (int i = 1; i <= q; ++i) printf("%d\n", f[c[i]][r[i]] ? 1 : 0);
}
void clear()
{
	for (int u = 1; u <= V; ++u)
	{
		to[u].clear();
		w[u].clear();
		for (int i = 0; i <= maxstep; ++i) f[u][i] = 0;
	}
}
void mian()
{
	clear();
	solveBF();
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) mian();
	return 0;
}