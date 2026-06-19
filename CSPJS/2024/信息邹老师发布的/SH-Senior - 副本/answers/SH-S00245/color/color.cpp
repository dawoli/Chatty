#include <bits/extc++.h>

#define inline __always_inline
template <typename T> inline void chkmin(T &x, const T &y) { if (x > y) x = y; }
template <typename T> inline void chkmax(T &x, const T &y) { if (x < y) x = y; }
template <typename T> inline void read(T &x)
{
	char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar());
	for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
}
const int MaxN = 2e5 + 5, MaxA = 1e6 + 5;
const int64_t inf = 1e18;

int n, a[MaxN], l[MaxA];
int64_t s[MaxN], f[MaxN][2];
inline int chk(int x, int y) { return x == y ? x : 0; }
inline int64_t sum(int l, int r) { return s[r] - s[l]; }
void test_case()
{
	read(n);
	memset(l, 0, n + 1 << 2);
	memset(s, 0, n + 1 << 3);
	memset(f, 0xc0, (n + 1) * sizeof(f[0]));
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + chk(a[i], a[i - 1]);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int64_t p = sum(j, i - 1) + chk(a[i], a[j]);
			chkmax(f[i][0], f[j][0] + p);
			chkmax(f[i][0], f[j][1] + p);
		}
		l[a[i]] = i;
		if (l[a[i + 1]])
		{
			int k = l[a[i + 1]];
			int64_t p = sum(k + 1, i) + a[i + 1];
			for (int j = 0; j < k; j++)
			{
				int64_t q = sum(j + 1, k) + p + chk(a[k + 1], a[j]);
				chkmax(f[i][1], f[j][0] + q);
				chkmax(f[i][1], f[j][1] + q);
			}
		}
	}
	printf("%ld\n", f[n][0]);
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t; read(t);
	while (t--) test_case();
	return 0;
}