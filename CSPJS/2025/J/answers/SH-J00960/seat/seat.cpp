#include <bits/stdc++.h>
#define int128 unsigned long long
using namespace std;
int128 a[10001];
bool cmp (int128 lhs, int128 rhs)
{
	return lhs > rhs;
}
int main ()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int128 n, m;
	cin >> n >> m;
	for (int128 i = 1; i <= n * m; i++)
		cin >> a[i];
	int128 r = a[1], p;
	sort(a + 1, a + n * m + 1, cmp);
	for (int128 i = 1; i <= n * m; i++)
	{
		if (a[i] == r)
		{
			p = i;
			break;
		}
	}
	int128 c, l;
	if (p % n == 0)
	{
		c = p / n;
		if (c % 2 == 1) l = n;
		else l = 1;
	}
	else
	{
		c = p / n + 1;
		if (c % 2 == 1) l = p % n;
		else l = n - p % n + 1;
	}
	cout << c << " " << l;
	return 0;
}
