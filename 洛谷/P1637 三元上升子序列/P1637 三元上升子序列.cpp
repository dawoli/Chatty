// Problem URL: https://www.luogu.com.cn/problem/P1637
// Finish Time: 2026/7/23 12:19:31 AC
// Start Time: 2026/7/23 11:54:10

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 3e4 + 10;
int		  n, m;
int		  c1[MAXN], c2[MAXN];
int		  a[MAXN], _a[MAXN];
int		  l[MAXN], r[MAXN];

auto query(int val)
{
	return lower_bound(_a + 1, _a + m + 1, val) - _a;
}

auto lowbit(int x)
{
	return x & -x;
}

void add(int c[], int pos, int val)
{
	while (pos <= MAXN)
	{
		c[pos] += val;
		pos += lowbit(pos);
	}
}

int sum(int c[], int pos)
{
	int res = 0;
	while (pos > 0)
	{
		res += c[pos];
		pos -= lowbit(pos);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		_a[i] = a[i];
	}
	sort(_a + 1, _a + n + 1);
	m = unique(_a + 1, _a + n + 1) - (_a + 1);

	for (int i = 1; i <= n; ++i)
	{
		add(c1, query(a[i]), 1);
		l[i] = sum(c1, query(a[i]) - 1);
	}
	for (int i = n; i >= 1; --i)
	{
		add(c2, query(a[i]), 1);
		r[i] = n - i - (sum(c2, query(a[i])) - 1);
	}
	ll ans = 0;
	for (int i = 2; i < n; ++i)
		ans += l[i] * r[i];
	cout << ans;
	return 0;
}