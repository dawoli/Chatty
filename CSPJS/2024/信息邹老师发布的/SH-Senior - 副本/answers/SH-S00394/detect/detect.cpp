#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, m, L, V, p[N];
double l[N], r[N];
map<int, int> ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r); 
		ans.clear();
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++)
		{
			int d, v, a;
			cin >> d >> v >> a;
			if (a > 0)
			{
				if (v > V)
				{
					l[i] = d - 1, r[i] = L + 1;
					continue;
				}
				double cnt = (1.0 * V * V - 1.0 * v * v) / (2 * a) + d;
				if (cnt <= L)
					l[i] = cnt, r[i] = L + 1;
			}
			else if (a < 0)
			{
				if (v <= V)
				{
					continue;
				}
				double cnt = (1.0 * V * V - 1.0 * v * v) / (2 * a) + d;
				l[i] = d - 1, r[i] = min(1.0 * L + 1, cnt);
			}
			else
			{
				if (v > V)
					l[i] = d - 1, r[i] = L + 1;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> p[i];
			for (int j = 1; j <= n; j++)
				if (p[i] > l[j] && p[i] < r[j])
					ans[j]++;
		}
		cout << ans.size() << " ";
		ans.clear();
		int pre = 0, cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				if (p[i] > l[j] && p[i] < r[j])
					ans[j]++;
			if (ans.size() == pre)
				cnt++;
			pre = ans.size();
		}
		cout << cnt << endl;
	}
}
