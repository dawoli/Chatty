#include <bits/stdc++.h>
using namespace std;
const int mod = 4;
int n, m, k, x, y, d;
int ans[6];
struct item
{
	int px, py;
	bool operator < (const item&tmp) const
	{
		if (px != tmp.px)
			return px < tmp.px;
		return py < tmp.py;
	} 
};
int cx()
{
	if (d == 0)
		return x;
	else if (d == 1)
		return x + 1;
	else if (d == 2)
		return x;
	else if (d == 3)
		return x - 1;
}
int cy()
{
	if (d == 0)
		return y + 1;
	else if (d == 1)
		return y;
	else if (d == 2)
		return y - 1;
	else if (d == 3)
		return y;
}
void cd()
{
	d = (d + 1) % mod;
} 
char a[1009][1009];
set <item> s;
set <item> ::iterator it;
int main ()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cin >> n >> m >> k >> x >> y >> d;
		s.clear();
		for (int i = 0; i < 1009; i++)
		{
			for (int j = 0; j < 1009; j++)
				a[i][j] = 'x';
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		for (int i = 0; i <= k; i++)
		{ 
			item t;
			t.px = x;
			t.py = y;
			s.insert(t);
			if (cx() <= 0 || cy() <= 0 || cx() >= 1009 || cy() >= 1009)
			{
				cd();
			}
			else if (a[cx()][cy()] == 'x')
			{
				cd();
			}
			else
			{
				x = cx();
				y = cy();
			}
		}
		ans[q] = s.size();
	}
	for (int i = 1; i <= t; i++)
		cout << ans[i] << "\n";
	return 0;
}
