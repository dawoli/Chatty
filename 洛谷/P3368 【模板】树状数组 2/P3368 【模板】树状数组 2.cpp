// Problem URL: https://www.luogu.com.cn/problem/P3368
// Finish Time: 2026/7/16 15:30:34 AC
// Start Time: 2026/7/16 15:20:39

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned int uint;
const unsigned int	 MAXN = 5e5 + 5;

int n, m, a[MAXN], b[MAXN], c[MAXN];

// Fenwick Tree
auto lowbit(const int &x)
{
	return x & -x;
}

auto add(const uint &x, const int &v)
{
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += v;
}

auto range_add(const uint &l, const uint &r, const int &v)
{
	add(l, v);
	add(r + 1, -v);
}

auto query(const uint &x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += c[i];
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		b[i] = a[i] - a[i - 1];
		add(i, b[i]);
	}

	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			range_add(x, y, k);
		}
		else
		{
			int x;
			cin >> x;
			cout << query(x) << endl;
		}
	}
	return 0;
}