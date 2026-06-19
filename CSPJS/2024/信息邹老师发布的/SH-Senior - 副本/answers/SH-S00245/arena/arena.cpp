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

int main()
{
	freopen("arena.in", "r", stdin);
	return 0;
}