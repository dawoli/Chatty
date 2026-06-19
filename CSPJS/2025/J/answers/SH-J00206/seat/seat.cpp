# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 110;
ll n, m, k, p, x;
ll a[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	k = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%lld", &a[++k]);
		}
	}
	x = a[1];
	sort(a + 1, a + k + 1, greater <ll> ());
	for (int i = 1; i <= k; i++)
	{
		if (a[i] == x) p = i;
	}
	x = p / n;
	if (p % n)
	{
		if (x & 1) printf("%lld %lld\n", x + 1, n - p % n + 1);
		else printf("%lld %lld\n", x + 1, p % n);
	}
	else
	{
		if (x & 1) printf("%lld %lld\n", x, n);
		else printf("%lld 1\n", x);
	}
	return 0;
}
