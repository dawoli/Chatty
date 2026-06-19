#include <iostream>
using namespace std;
const int N = 100005, M = 1000005;
long long T, n, m, L, V, ans1, ans2, d[N], v[N], a[N], x, x1, x2, x3, f1[N], f2[N], y;
bool p[M], f[N], flag;
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i ++)
	{
		cin >> n >> m >> L >> V;
		for (int j = 1; j <= n; j ++)
		{
			cin >> d[j] >> v[j] >> a[j];
		}
		for (int j = 1; j < M; j ++)
		{
			p[j] = false;
		}
		for (int j = 1; j <= m; j ++)
		{
			cin >> x;
			p[x] = true;
		}
		ans1 = 0;
		ans2 = 0;
		for (int j = 1; j <= n; j ++)
		{
			f2[j] = M + 10;
			if ((v[j] <= V) && (a[j] > 0))
			{
				x1 = V * V - v[j] * v[j];
				x2 = 2 * a[j];
				x3 = min(x1 / x2 + 1 + d[j], L + 1);
				flag = false;
				for (int k = x3; k <= L; k ++)
				{
					if (p[k])
					{
						ans1 ++;
						flag = true;
						break;
					}
				}
				if (flag)
				{
					f1[j] = x3;
					f2[j] = L;
				}
			}
			else if (v[j] > V)
			{
				x3 = L;
				if (a[j] < 0)
				{
					x1 =  v[j] * v[j] - V * V;
					x2 = (-2) * a[j];
					x3 = min(x1 / x2 + d[j], L);
					if (x1 % x2 == 0)
					{
						x3 --;
					}
				}
				flag = false;
				for (int k = d[j]; k <= x3; k ++)
				{
					if (p[k])
					{
						ans1 ++;
						flag = true;
						break;
					}
				}
				if (flag)
				{
					f1[j] = d[j];
					f2[j] = x3;
				}
			}
		}
		cout << ans1 << " ";
		for (int j = 1; j <= n; j ++)
		{
			for (int k = 1; k < j; k ++)
			{
				if (f2[j] < f2[k])
				{
					swap(f1[j], f1[k]);
					swap(f2[j], f2[k]);
				}
			}
		}
		for (int j = 1; j <= n; j ++)
		{
			f[j] = false;
		}
		for (int j = 1; j <= n; j ++)
		{
			if (f[j])
			{
				continue;
			}
			if (f2[j] == M + 10)
			{
				break;
			}
			for (int k = f2[j]; k >= f1[j]; k --)
			{
				if (p[k])
				{
					ans2 ++;
					y = k;
					break;
				}
			}
			for (int k = j; k <= L; k ++)
			{
				if (f1[k] <= y)
				{
					f[k] = true;
				}
			}
		}
		ans2 = m - ans2;
		cout << ans2 << endl;
	}
	return 0;
}
