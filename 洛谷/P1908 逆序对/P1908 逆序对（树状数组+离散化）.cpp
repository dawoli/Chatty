// Problem URL: https://www.luogu.com.cn/problem/P1908
// Finish Time: 2026/7/16 16:03:19 AC
// Start Time: 2026/7/16 15:48:06

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 5e5 + 5;

int		  n, t[MAXN], r[MAXN];
long long ans;

struct point
{
	int m, v;
} a[MAXN];

auto cmp(point q, point w)
{
	if (q.v == w.v)
		return q.m < w.m;
	return q.v < w.v;
}

auto lowbit(const int &x)
{
	return x & -x;
}

auto add(int p, const int &d)
{
	for (; p <= n; p += lowbit(p))
		t[p] += d;
}

auto sum(int p)
{
	int s = 0;
	for (; p; p -= lowbit(p))
		s += t[p];
	return s;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].v, a[i].m = i;

	sort(a + 1, a + 1 + n, cmp);

	for (int i = 1; i <= n; i++)
		r[a[i].m] = i;

	for (int i = 1; i <= n; i++)
	{
		add(r[i], 1);
		ans += i - sum(r[i]);
	}
	cout << ans;
	return 0;
}