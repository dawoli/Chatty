#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node
{
	int l, r;
};

int t, n, m, l, vm;
int d[N], v[N], a[N], p[N];
vector<node> q;

bool cmp(node x, node y)
{
	if (x.l == y.l)
	{
		return x.r < y.r;
	}
	return x.l < y.l;
}

void solve()
{
	q.clear();
	cin >> n >> m >> l >> vm;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> v[i] >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
	}
	sort(p + 1, p + m + 1);
	p[m + 1] = INT_MAX;
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			if (v[i] > vm)
			{
				int it = lower_bound(p + 1, p + m + 2, d[i]) - p;
				if (it == m + 1)
				{
					continue;
				}
				ans1++;
				q.push_back((node){it, m});
			} 
			else
			{
				int x = (vm * vm - v[i] * v[i]) / (2 * a[i]) + 1;
				int it = lower_bound(p + 1, p + m + 2, x + d[i]) - p;
				if (it == m + 1)
				{
					continue;
				}
				ans1++;
				q.push_back((node){it, m});
			}
		}
		else if (a[i] == 0)
		{
			if (v[i] > vm)
			{
				int it = lower_bound(p + 1, p + m + 2, d[i]) - p;
				if (it == m + 1)
				{
					continue;
				}
				ans1++;
				q.push_back((node){it, m});
			} 
		}
		else
		{
			if (v[i] <= vm)
			{
				continue;
			}
			int x = ceil((1.0 * (vm * vm - v[i] * v[i])) / (2 * a[i])) - 1;
			int it1 = lower_bound(p + 1, p + m + 2, d[i]) - p;
			if (it1 == m + 1)
			{
				continue;
			}
			int it2 = upper_bound(p + 1, p + m + 2, x + d[i]) - p - 1;
			if (it1 > it2)
			{
				continue;
			}
			ans1++;
//			cout << it1 << " " << it2 << endl;
			q.push_back((node){it1, it2});
		}
	}
	sort(q.begin(), q.end(), cmp);
	int ll, rr;
	for (int i = 0; i < ans1; i++)
	{
		ll = q[i].l, rr = q[i].r;
		ans2++;
		while (ll <= q[i + 1].r && rr >= q[i + 1].l)
		{
			i++;
			ll = max(ll, q[i].l);
			rr = min(rr, q[i].r);
		}
	}
	cout << ans1 << " " << m - ans2 << endl;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
