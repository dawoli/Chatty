#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+10;
ll t, n, a[N];
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		ll ans = 0;
		a[0] = -1;
		for (int i = 0; i < (1 << n); i += 2)
		{
			ll temp = 0;
			ll red = 0, blue = 0;
			for (int j = 1; j <= n; j++)
			{
				if (i & (1 << j))
				{
					if (a[j] == a[red]) temp += a[j];
					red = j;
				}
				else
				{
					if (a[j] == a[blue]) temp += a[j];
					blue = j;
				}
			}
			ans = max(ans, temp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
