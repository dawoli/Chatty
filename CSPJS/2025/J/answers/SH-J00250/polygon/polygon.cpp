#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[5005];

int choose(int x, int sum, int maxn)
{
	if (a[x] == 0) return 0;
	sum += a[x];
	if (sum <= 2 * maxn) return max(choose(x+1, sum-a[x], maxn), choose(x+1, sum, max(maxn, a[x])));
	return 1 + max(choose(x+1, sum-a[x], maxn), choose(x+1, sum, max(maxn, a[x])));
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	if (n == 3)
	{
		if ((a[1]+a[2]+a[3]) > 2*max(a[1], max(a[2], a[3])))
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		ans += choose(i, 0, -1);
		ans %= 998244353;
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
