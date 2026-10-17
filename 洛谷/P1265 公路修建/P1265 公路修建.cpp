// Problem URL: https://www.luogu.com.cn/problem/P1265 公路修建
// Finish Time: 2026/10/7 11:16:17 AC
// Start Time: 2026/10/7 10:27:04

#include <bits/stdc++.h>
#include <climits>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 5e3 + 3;

int			 n;
pii			 c[MAXN];
double		 dis[MAXN], ans;
bitset<MAXN> vis;

double get_dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Prim()
{
	dis[1] = 0.0;
	vis[1] = true;
	int	   x;
	double mn;
	for (int i = 1; i <= n; i++)
	{
		x  = 1;
		mn = 1e9 * 1.0;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < mn)
				mn = dis[j], x = j;
		vis[x] = true;
		ans += dis[x];
		for (int j = 1; j <= n; j++)
			dis[j] = min(dis[j], get_dis(c[x].first, c[x].second, c[j].first, c[j].second));
	}
	cout << fixed << setprecision(2) << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].first >> c[i].second;
		dis[i] = 1e12 * 1.0;
	}
	Prim();
	return 0;
}