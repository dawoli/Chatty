#include<bits/stdc++.h>
using namespace std;
int a[5005], b[5005];
long long m = 998244353;
long long ans = 0;
int n;
int k;
void dfs(int idx, int sum, int maxn)
{
	if(k <= 2 * maxn)return;
	if(idx == n + 1)
	{
		if(sum > maxn * 2)
		{
			ans = (ans + 1) % m;
		}
		return;
	}
	dfs(idx + 1, sum + a[idx], max(maxn, a[idx]));
	dfs(idx + 1, sum, maxn);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		k += a[i];
	}
	dfs(1, 0, 0);
	cout << ans << "\n";
	return 0;
}
