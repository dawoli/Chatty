#include <bits/stdc++.h>
using namespace std;

int t;
int n;

struct Mem
{
	int a, b, c;
} a[100005], temp[100005];

set<int> c1;
set<int> c2;
set<int> c3;

bool cmp1(const Mem &x, const Mem &y)
{
	return min(x.a - x.b, x.a - x.c) > min(y.a - y.b, y.a - y.c);
}
bool cmp2(const Mem &x, const Mem &y)
{
	return min(x.b - x.a, x.b - x.c) > min(y.b - y.a, y.b - y.c);
}
bool cmp3(const Mem &x, const Mem &y)
{
	return min(x.c - x.a, x.c - x.b) > min(y.c - y.a, y.c - y.b);
}

void solve()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	c1.clear();
	c2.clear();
	c3.clear();
	int summ = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
		if (a[i].a > a[i].b && a[i].a > a[i].c)
			c1.insert(i);
		else if (a[i].b > a[i].a && a[i].b > a[i].c)
			c2.insert(i);
		else
			c3.insert(i);
		summ += max(a[i].a, max(a[i].b, a[i].c));
	}
	if (c1.size() > n / 2)
	{
		int cnt = 0;
		for (auto i : c1)
		{
			temp[++cnt] = Mem{a[i].a, a[i].b, a[i].c};
		}
		sort(temp + 1, temp + cnt + 1, cmp1);
		for (int i = cnt; i > n / 2; i--)
		{
			summ -= min(temp[i].a - temp[i].b, temp[i].a - temp[i].c);
		}
	}
	else if (c2.size() > n / 2)
	{
		int cnt = 0;
		for (auto i : c2)
		{
			temp[++cnt] = Mem{a[i].a, a[i].b, a[i].c};
		}
		sort(temp + 1, temp + cnt + 1, cmp2);
		for (int i = cnt; i > n / 2; i--)
		{
			summ -= min(temp[i].b - temp[i].a, temp[i].b - temp[i].c);
		}
	}
	else if (c3.size() > n / 2)
	{
		int cnt = 0;
		for (auto i : c3)
		{
			temp[++cnt] = Mem{a[i].a, a[i].b, a[i].c};
		}
		sort(temp + 1, temp + cnt + 1, cmp3);
		for (int i = cnt; i > n / 2; i--)
		{
			summ -= min(temp[i].c - temp[i].a, temp[i].c - temp[i].b);
		}
	}
	printf("%d\n", summ);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (;t--;)
		solve();
	return 0;
}
