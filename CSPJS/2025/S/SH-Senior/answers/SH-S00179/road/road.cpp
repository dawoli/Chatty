#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

const int N = 2e6+10;
int n, m, k;
int hd[N], cnt = 0; // 链式前向星套装 
int vis[N], dis[N];

// 链式前向星存图 
struct Edge
{
	int to, nxt, val;	
}e[N];

// 链式前向星加边函数
inline void add(int u, int v, int w)
{
	e[++cnt].val = w;
	e[cnt].nxt = v;
	e[cnt].to = hd[u];
	hd[u] = cnt;
}

struct Tree
{
	int dis, pos;
	bool operator<(const Tree &x) const
	{
		return x.dis < dis;
	}
};

priority_queue <Tree> pq;

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;

	// 这里常规的存图 
	for (int i = 1; i <= n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w); // 双向图 
	}
	
	if (k == 1)
	{
		// 此时只要跑最小生成树即可
		memset(dis, 0x3f, sizeof(dis));
//		int u = -1;
//		for (int i = 1; i <= n; i++)
//			if (!vis[i] && (u == -1 || dis[u] > dis[i]))
//				u = i;
		int u = 1;
		dis[u] = 0;
		pq.push({0, u});
		while (!pq.empty())
		{
			auto tmp = pq.top();
			u = tmp.pos;
			cout << u << '\n';
			pq.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (int i = hd[u]; i; i = e[u].nxt)
			{
				if (dis[u] + e[i].val < dis[i] && !vis[i])
				{
					dis[i] = dis[u] + e[i].val;
					pq.push({dis[i], i});
				}
			}
		}
//		int ans = 0;
//		for (int i = 1; i <= n; i++)
//			ans += dis[i];
//		cout << ans << '\n';
		cout << dis[4] << '\n';
		return 0;
	}
}
