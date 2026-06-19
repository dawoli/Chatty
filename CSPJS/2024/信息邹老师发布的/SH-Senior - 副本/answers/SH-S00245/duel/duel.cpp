#include <bits/extc++.h>

#define inline __always_inline
template <typename T> inline void read(T &x)
{
	char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar());
	for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + (ch - '0');
}
const int MaxN = 1e5 + 5;

int n, a[MaxN];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	int l = 1;
	for (int r = 1; r <= n; r++)
		if (a[r] > a[l]) l++;
	printf("%d", n - l + 1);
	return 0;
}