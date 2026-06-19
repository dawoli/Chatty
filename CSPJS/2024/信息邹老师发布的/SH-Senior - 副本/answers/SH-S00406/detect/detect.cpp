#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n , m , l , v , maxn , p[100005];
vector<int> g[100005];
bool off[100005];
struct car
{
	int d , v , a;
	void read()
	{
		cin >> d >> v >> a;
	}
} a[100005];
void dfs(int id , int cnt)
{
	if (id == m + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (g[i].size() == 0) continue;
			bool flag = true;
			for (int j : g[i])
			{
				if (!off[j])
				{
					flag = false;
					break;
				}
			}
			if (flag) return;
		}
		maxn = max(maxn , cnt);
		return;
	}
	off[id] = false;
	dfs(id + 1 , cnt);
	off[id] = true;
	dfs(id + 1 , cnt + 1);
}
void solve()
{
	maxn = 0;
	cin >> n >> m >> l >> v;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++) a[i].read();
	for (int i = 1; i <= m; i++) cin >> p[i];
	int cnt = 0;
	bool t = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].a < 0) t = false;
		bool flag = false;
		for (int j = 1; j <= m; j++)
		{
			if (p[j] < a[i].d) continue;
			double x = sqrt(a[i].v * a[i].v + 2 * a[i].a * (p[j] - a[i].d));
			if (x <= 0) break;
			if (x > v)
			{
				flag = true;
				g[i].push_back(j);
			}
		}
		if (flag) cnt ++;
	}
	if (t) maxn = m - 1;
	else dfs(1 , 0);
	cout << cnt << ' ' << maxn << endl;
}
int main()
{
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	int t; cin >> t;
	while (t --) solve();
	return 0;
}
