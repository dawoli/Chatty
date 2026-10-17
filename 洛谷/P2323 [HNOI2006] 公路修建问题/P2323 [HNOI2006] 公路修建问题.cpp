// Problem URL: https://www.luogu.com.cn/problem/P2323 [HNOI2006] 公路修建问题
// Finish Time: 2026/10/11 18:55:04 AC
// Start Time: 2026/10/11 18:11:49

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 2e4 + 5;

struct node
{
	int u;
	int v;
	int w1;
	int w2;
	int id;
} r[MAXN];
pii ans[MAXN];
int flag = 0;
int vis[MAXN];
int fa[MAXN];
int n, k, m, mn = 0;

bool merge(int, int);
int	 get_father(int);
void kruskal1();
void kruskal2();
bool cmp1(node, node);
bool cmp2(node, node);
bool cmp3(pii, pii);

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> m;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m - 1; i++)
	{
		cin >> r[i].u >> r[i].v >> r[i].w1 >> r[i].w2;
		r[i].id = i;
	}
	sort(r + 1, r + m, cmp1);
	kruskal1();
	sort(r + 1, r + m, cmp2);
	kruskal2();
	sort(ans + 1, ans + n, cmp3);
	cout << mn << endl;
	for (int i = 1; i <= n - 1; i++)
		cout << ans[i].first << ans[i].second;
	return 0;
}

bool cmp1(node x, node y)
{
	return x.w1 < y.w1;
}

bool cmp2(node x, node y)
{
	return x.w2 < y.w2;
}

bool cmp3(pii x, pii y)
{
	return x.first < y.first;
}

int get_father(int x)
{
	if (x == fa[x])
		return x;
	else
	{
		fa[x] = get_father(fa[x]);
		return fa[x];
	}
}

bool merge(int x, int y)
{
	int f1 = get_father(x), f2 = get_father(y);
	if (f1 == f2)
		return false;
	else
	{
		fa[f2] = f1;
		return true;
	}
}

void kruskal1()
{
	int st = 0;
	for (int i = 1; i <= m - 1; i++)
	{
		if (vis[r[i].id] == 0)
			if (merge(r[i].u, r[i].v))
			{
				vis[r[i].id] = 1;
				flag++;
				st++;
				mn				 = max(mn, r[i].w1);
				ans[flag].first	 = r[i].id;
				ans[flag].second = 1;
			}
		if (st == k)
			return;
	}
}

void kruskal2()
{
	int st = 0;
	for (int i = 1; i <= m - 1; i++)
	{
		if (vis[r[i].id] == 0)
			if (merge(r[i].u, r[i].v))
			{
				vis[r[i].id] = 1;
				flag++;
				st++;
				mn				 = max(mn, r[i].w2);
				ans[flag].first	 = r[i].id;
				ans[flag].second = 2;
			}
		if (st == n - 1 - k)
			return;
	}
}