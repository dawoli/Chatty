#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
const int _ = 5000 + 9;
long long ans;
int n, a[_];
void dfs(int x, int num, int mx, int sum)
{
	if(x == n + 1)
	{
		if(num >= 3 && sum > 2 * mx)
			ans = (ans + 1) % mod;
		return;
	}
	if(n - x + 1 + num < 3)
		return;
	dfs(x + 1, num, mx, sum);
	dfs(x + 1, num + 1, (int)max(mx, a[x]), sum + a[x]);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1, 0, 0, 0);
	cout << ans;
	
	return 0;
}
