#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 1000010;

int d[N], v[N], a[N];
int p[M];
bool g[110][110];

bool check1(int x)
{
	for (int i = 1; i <= x; i++)
	{
		if (a[i] != 0)
			return false;
	}
	return true;
}

bool check2(int x)
{
	for (int i = 1; i <= x; i++)
	{
		if (a[i] <= 0)
			return false;
	}
	return true;
}

bool check3(int x)
{
	for (int i = 1; i <= x; i++)
	{
		if (a[i] >= 0)
			return false;
	}
	return true;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));
		memset(g, 0, sizeof(g));
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1; i <= m; i++)
			cin >> p[i];
		if (check1(n))
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (v[i] > V && d[i] <= p[m])
					ans++;
			}
			if (ans == 0)	cout << ans << " " << m << endl;
			else	cout << ans << " " << m - 1 << endl;
		}
		else if (check2(n))
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (d[i] <= p[m] && v[i] * v[i] + 2 * a[i] * (p[m] - d[i]) > V * V)
					ans++;
			}
			if (ans == 0)	cout << ans << " " << m << endl;
			else	cout << ans << " " << m - 1 << endl;
		}
		else if (n <= 20)
		{
			int ans1 = 0, ans2 = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
				{
					if (d[i] <= p[j] && v[i] * v[i] + 2 * a[i] * (p[j] - d[i]) > V * V)
						g[i][j] = 1, g[i][0] = 1;
				}
			for (int i = 1; i <= n; i++)
				if (g[i][0] == 1)
					ans1++;
			for (int k = 1; k <= m; k++)
			{
				int ans3 = 0;
				memset(g, 0, sizeof(g));
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= m; j++)
					{
						if (j == k)	continue;
						if (d[i] <= p[j] && v[i] * v[i] + 2 * a[i] * (p[j] - d[i]) > V * V)
							g[i][j] = 1, g[i][0] = 1;
					}
				for (int i = 1; i <= n; i++)
					if (g[i][0] == 1)
						ans3++;
				if (ans1 == ans3)	ans2++;
			}
			cout << ans1 << " " << ans2 << endl; 
		}
	}
	return 0;
}
