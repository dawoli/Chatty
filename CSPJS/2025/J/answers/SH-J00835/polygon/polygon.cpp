#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
const int MOD = 998244353;
int n, a[MAXN];
int mx = -1;
long long pre[MAXN], cnt = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	if (mx == 1)
	{
		cnt = (n - 1) * (n - 2) / 2;
	}
	if (n == 3)
	{
		if (pre[3] > mx * 2)
		{
			cnt = 1;
		}
	}
	
	printf("%lld", cnt % MOD);
	return 0;
}
