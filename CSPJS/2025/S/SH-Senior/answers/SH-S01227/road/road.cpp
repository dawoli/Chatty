#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 8;
const int MAXM = 1e6 + 8;
int n, m, k;
vector <int> adj[MAXN];
struct node
{
	int u, v, w;
	bool operator<(const node &x) const
	{
		return w > x.w;
	}
}edge[MAXM];
int dsu[MAXN];
int father[MAXN];
int getfather(int root)
{
	return (father[root] == root ? root : father[root] = getfather(father[root]));
}
void add(int u, int v)
{
	father[u] = dsu[v];
	getfather(u);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	priority_queue <node> q;
	for (int i = 1, u, v, w; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		edge[i] = (node){u, v, w};
		q.push(edge[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		dsu[i] = i;
		father[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		node cur = q.top();
		q.pop();
		if (getfather(dsu[cur.u]) == getfather(dsu[cur.v]))
		{
			i--;
			continue;
		}
		add(cur.u, cur.v);
		ans += cur.w;
	}
	cout << ans;
	return 0;
}

