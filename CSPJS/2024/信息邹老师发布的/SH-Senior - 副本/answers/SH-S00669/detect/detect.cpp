#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, L, V;
int d[100010], v[100010], a[100010];
int p[100010];

pair<int, int> lr[100010];
int areas;

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
	return (lhs.second < rhs.second);
}

bool check(int x, int dm)
{
	int cnt = areas; // remaining
	sort(lr + 1, lr + areas + 1, cmp);
	int tmp_last = -1;
	bool flag = false;
	for (int i = 1; i <= areas; i++)
	{
		int last = upper_bound(p + 1, p + m + 1, lr[i].second) - p - 1;
		if (tmp_last >= lr[i].first)
			cnt--, flag = true;
		else
			tmp_last = p[last], flag = false;
	}
	if (tmp_last < dm)
		cnt++;
	return (m - cnt >= x);
}

void solve()
{
	memset(lr, 0, sizeof(lr));
	areas = 1;
	int cnt = 0;
	int d_max1 = 0;
	double d_max2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > p[m])
			continue;
		if (a[i] == 0)
		{
			if (v[i] > V)
				cnt++, d_max1 = max(d_max1, d[i]);
		}
		else if (a[i] > 0)
		{
			if (v[i] > V)
				cnt++, d_max1 = max(d_max1, d[i]);
			else if (2 * a[i] * (p[m] - d[i]) > V * V - v[i] * v[i])
				cnt++, d_max2 = max(d_max2, d[i] + (V * V - v[i] * v[i]) / double(2.0) / a[i]);
		}
		else // O(logn), to be solved
		{
			if (v[i] > V)
			{
				int tmp = lower_bound(p + 1, p + m + 1, d[i]) - p;
				if (tmp <= m && 2 * a[i] * (p[tmp] - d[i]) > V * V - v[i] * v[i])
					cnt++, lr[areas++] = make_pair(d[i], min(L, int(floor(d[i] + (V * V - v[i] * v[i]) / double(2.0) / a[i]))));
			}
		}
	}
	cout << cnt << " ";
	
	d_max1 = max(d_max1, int(floor(d_max2)) + 1); // p'max >= d_max1;
	areas--;
	int left = 0, right = m, mid;
	while (left < right) // O(nlog^2n)
	{
		mid = (left + right + 1) / 2;
		if (check(mid, d_max1))
			left = mid;
		else
			right = mid - 1;
	}
	cout << left;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
	
	cin >> T;
    for (int i = 1; i <= T; i++)
    {
    	memset(d, 0, sizeof(d));
    	memset(v, 0, sizeof(v));
    	memset(a, 0, sizeof(a));
    	memset(p, 0, sizeof(p));
    	cin >> n >> m >> L >> V;
    	for (int j = 1; j <= n; j++)
    		cin >> d[j] >> v[j] >> a[j];
    	for (int j = 1; j <= m; j++)
    		cin >> p[j];
    	
    	solve();
    	cout << "\n";
	}
	
    return 0;
}
