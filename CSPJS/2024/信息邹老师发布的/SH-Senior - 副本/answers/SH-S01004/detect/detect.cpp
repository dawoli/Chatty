#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, m, L, V;
int d[N] = {}, v[N] = {}, a[N] = {};
int p[N] = {};
int fas = 0, ans = 0;
bool f[N] = {};
bool b[3010][3010] = {};
bool g[3010][3010] = {};
bool c[N] = {};
bool fc;

bool isLegal()
{
	bool flag;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			g[i][j] = b[i][j];
	}
	for (int i = 1; i <= m; i++)
	{
		if (c[i])
		{
			for (int j = 1; j <= n; j++)
				g[j][i] = false;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i])
		{
			flag = false;
			for (int j = 1; j <= m; j++)
			{
				if (g[i][j])
					flag = true;
			}
			if (!flag)
				return false;
		}
	}
	return true;
}

void cal(int s, int maxi)
{
	if (s > maxi)
	{
		if (isLegal())
		{
			ans = maxi;
			fc = true;
			return;
		}
	}
	else
	{
		for (int i = 1; i <= m; i++)
		{
			if (!c[i])
			{
				c[i] = true;
				cal(s + 1, maxi);
				if (fc)
					return;
				c[i] = false;
			}
		}
	}
}

void calc()
{
	fc = false;
	for (int i = m; i >= 1; i--)
	{
		if (fc)
			return;
		memset(c, false, sizeof(c));
		cal(1, i);
	}
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		fas = 0;
		ans = 0;
		memset(b, false, sizeof(b));
		memset(c, false, sizeof(c));
		memset(f, false, sizeof(f));
		cin >> n >> m >> L >> V;
		for (int j = 1; j <= n; j++)
			cin >> d[j] >> v[j] >> a[j];
		for (int j = 1; j <= m; j++)
			cin >> p[j];
		for (int j = 1; j <= n; j++)
		{
			bool flag = false;
			if (a[j] == 0)
			{
				for (int k = 1; k <= m; k++)
				{
					if (p[k] >= d[j] && v[j] > V)
					{
						flag = true;
						b[j][k] = true;
					}
				}
			}
			else if (a[j] > 0)
			{
				for (int k = 1; k <= m; k++)
				{
					if (p[k] >= d[j] &&
					sqrt((double)(v[j] * v[j] + 2 * a[j] * (p[k] - d[j]))) > V)
					{
						flag = true;
						b[j][k] = true;
					}
				}
			}
			else if (a[j] < 0)
			{
				for (int k = 1; k <= m; k++)
				{
					if (p[k] >= d[j] &&
					p[k] <= d[j] - v[j] * v[j] / 2.0 / a[j] &&
					sqrt((double)(v[j] * v[j] + 2 * a[j] * (p[k] - d[j]))) > V)
					{
						flag = true;
						b[j][k] = true;
					}
				}
			}
			if (flag)
			{
				f[j] = true;
				fas++;
			}
		}
		calc();
		cout << fas << " " << ans << endl;
	}
	return 0;
}
