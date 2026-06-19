#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 0.00000001;
int n, m, l, v, c[100005];

struct node
{
	double l, r;
	int k;
} b[100005], e[100005], f[100005];

bool cmp(node x, node y)
{
	if (x.l != y.l) return x.l < y.l;
	return x.r < y.r;
}

signed main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> l >> v;
		int cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			int d1, x1, a1;
			scanf("%lld%lld%lld", &d1, &x1, &a1);
			double d = d1, x = x1, a = a1;
			if (a == 0)
			{
				if (x > v) b[++cnt2] = node {d, 10000000, 0};
			}
			else if (a > 0)
			{
				double y = (v * v - x * x) / 2.0 / a;
				if (x > v) b[++cnt2] = node {d, 10000000, 0};
				else if (d + y <= l) b[++cnt2] = node {d + y + eps, 10000000, 0}; 
			}
			else
			{
				double y = (v * v - x * x) / 2.0 / a;
				if (x > v) b[++cnt2] = node {d, d + y - eps, 0};
			}
		}
		sort(b + 1, b + cnt2 + 1, cmp);
		int j = 1;
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%lld", &c[i]);
			while (j <= cnt2 && b[j].r < c[i]) j++;
			while (j <= cnt2 && b[j].l <= c[i] && c[i] <= b[j].r)
			{
				e[++cnt] = node {b[j].l, b[j].r, c[i]}, j++;
				while (j <= cnt2 && b[j].r < c[i]) j++;
			}
		}
		int ans = 0;
		cout << cnt << " ";
		for (int i = 1; i <= cnt; i++)
		{
			double x = e[i].r;
			while (e[i + 1].k < x && i + 1 <= cnt) i++, x = min(x, e[i].r);
			ans++;
		}
		cout << m - ans << "\n";
	}
	return 0;
}
