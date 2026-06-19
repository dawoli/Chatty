#include <bits/stdc++.h>
using namespace std;
int n,m,a1,a;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &a1);
	int rk = 1;
	for (int i = 2; i <= n * m; ++i)
	{
		scanf("%d", &a);
		if (a > a1) ++rk;
	}
	int c = 1,r = 1;
	for (int i = 2; i <= rk; ++i)
	{
		int nr = r + ((c & 1) ? 1 : -1);
		if (nr < 1 || nr > n) ++c;
		else r = nr;
	}
	printf("%d %d\n", c, r);
	return 0;
}