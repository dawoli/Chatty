// Problem URL: https://www.luogu.com.cn/problem/P1250
// Finish Time: 2026/8/17 14:53:28 AC
// Start Time: 2026/8/17 14:34:33

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 3e4 + 4;
const int		  MAXH = 5e3 + 3;

int			 n, h, ans = 0;
bitset<MAXN> t;

struct node
{
	int b, e, t;
} c[MAXH];

bool operator<(const node &_a, const node &_b)
{
	return _a.e < _b.e;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> h;
	for (int i = 1; i <= h; i++)
		cin >> c[i].b >> c[i].e >> c[i].t;
	sort(c + 1, c + h + 1);
	for (int i = 1; i <= h; i++)
	{
		auto &f = c[i];
		int	  x = 0;
		for (int j = f.b; j <= f.e; j++)
			if (t[j])
				x++;
		for (int j = f.e; j >= f.b && x < f.t; j--)
			if (!t[j])
				x++, ans++, t[j] = true;
	}
	cout << ans;
	return 0;
}