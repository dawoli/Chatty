// Problem URL: https://www.luogu.com.cn/problem/P3374
// Finish Time: 2026/7/14 12:43:43 AC
// Start Time: 2026/7/14 12:31:30

// Categories: 数据结构：树状数组
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
int		  n, m, a[MAXN], c[MAXN];

auto lowbit(const int &x)
{
	return x & -x;
}

auto add(const int &x, const int &v)
{
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += v;
}

auto prefix_sum(const int &x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += c[i];
	return res;
}

auto sum(const int &l, const int &r)
{
	return prefix_sum(r) - prefix_sum(l - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		add(i, a[i]);
	}

	while (m--)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)
			add(x, y);
		else
			cout << sum(x, y) << endl;
	}
	return 0;
}