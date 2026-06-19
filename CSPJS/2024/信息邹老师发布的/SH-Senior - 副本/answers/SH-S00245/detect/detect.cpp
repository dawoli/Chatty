#include <bits/extc++.h>

#define inline __always_inline
template <typename T> inline void read(T &x)
{
	char ch; bool flag = false;
	for (ch = getchar(); !isdigit(ch); ch = getchar()) flag = ch == '-';
	for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
	if (flag) x = -x;
}
const int MaxN = 1e5 + 5, MaxM = MaxN, MaxA = 1e6 + 5;

int n, m, l, lim, p[MaxN];
template <typename T> inline T upper_div(const T &x, const T &y) { return (x + y - 1) / y; }
struct car_t 
{ 
	int v, a, d, s, t;
	inline void init() // [s, t) overspeed interval
	{
		if (v > lim)
		{
			s = d;
			if (a >= 0) t = l + 1;
			else t = d + upper_div(1l * v * v - 1l * lim * lim, -2l * a);
		}
		else
		{
			t = l + 1;
			if (a <= 0) s = l + 1;
			else s = d + (1l * lim * lim - 1l * v * v) / (2l * a) + 1;
		}
	}
} car[MaxN];
struct segment_t { int l, r; } s[MaxN];
void test_case()
{
	read(n), read(m), read(l), read(lim);
	for (int i = 1; i <= n; i++)
		read(car[i].d), read(car[i].v), read(car[i].a), car[i].init();
	for (int i = 1; i <= m; i++) read(p[i]);
	int ans = 0, sub = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = std::lower_bound(p + 1, p + m + 1, car[i].s) - p;
		if (x <= m && p[x] < car[i].t)
			ans++, s[cnt++] = {car[i].s, car[i].t};
	}
	std::sort(s, s + cnt, [](const segment_t &x, const segment_t &y) { return x.r < y.r; });
	int x = 1, l = -1;
	for (int i = 0; i < cnt; i++)
	{
		if (s[i].l <= l) continue;
		while(x + 1 <= m && p[x + 1] < s[i].r) x++;
		l = p[x], sub++;
	}
	printf("%d %d\n", ans, m - sub);
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t; read(t);
	while (t--) test_case();
	return 0;
}