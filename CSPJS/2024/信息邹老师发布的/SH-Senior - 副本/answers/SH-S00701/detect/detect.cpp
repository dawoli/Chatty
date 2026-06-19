#include <iostream> 
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
struct car{
	int d, v, a, d1, d2;
}c[N];
int p[N], n, m, L, v0, l[N], r[N], dp[N], ans1 = 0, ans2 = 0;
bool f[N], f1[N];
vector <int> g[N];
bool cmp(car x, car y){
	if (x.d1 != y.d1) return x.d1 < y.d1;
	return x.d2 < y.d2;
}
void dfs(int x, int s)
{
	if (x > m)
	{
		for (int i = 1; i <= n; i++)
			if (!f[i]) return;
		ans2 = max(ans2, s);
		return;
	}
	dfs(x + 1, s + 1);
	for (int i = 0; i < g[x].size(); i++)
	{
		f1[g[x][i]] = f[g[x][i]];
		f[g[x][i]] = 1;
	}
	dfs(x + 1, s);
	for (int i = 0; i < g[x].size(); i++) f[g[x][i]] = f1[g[x][i]];
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(f1, 0, sizeof f1);
		memset(f, 0, sizeof f);
		memset(l, 0, sizeof l);
		memset(r, 0x3f, sizeof r);
		memset(dp, 0x3f, sizeof dp);
		cin >> n >> m >> L >> v0;
		bool flag = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
			if (c[i].a < 0) flag = 0;
			if (c[i].v <= v0 && c[i].a > 0){
				c[i].d1 = max(0, min(L, c[i].d + (v0 * v0 - c[i].v * c[i].v + 1) / (2 * c[i].a)));
				c[i].d2 = L;
			}
			else if (c[i].v > v0 && c[i].a < 0){
				c[i].d2 = max(0, min(L, c[i].d + (v0 * v0 - c[i].v * c[i].v + 1) / (2 * c[i].a)));
				c[i].d1 = c[i].d;
			}
			else if (c[i].v > v0 && c[i].a >= 0){
				c[i].d1 = c[i].d;
				c[i].d2 = L;
			}
			else c[i].d2 = -1;
		}
		ans1 = 0, ans2 = 0;
		for (int i = 1; i <= m; i++) cin >> p[i];
		sort(p + 1, p + m + 1);
		if (flag)
		{
			for (int i = 1; i <= n; i++)
				if (c[i].d1 <= p[m] && p[m] <= c[i].d2) ans1++;
			cout << ans1 << " " << n - 1 << endl;
		}
		else 
		{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					if (c[i].d1 <= p[j] && p[j] <= c[i].d2)
					{
						f[i] = 1;
						g[j].push_back(i);
					}
			for (int i = 1; i <= n; i++)
				if (f[i]) ans1++;
			cout << ans1 << " ";
			memset(f, 0, sizeof f);
			dfs(1, 0);
			cout << ans2 << endl;
		} 
	}
	return 0;
}
