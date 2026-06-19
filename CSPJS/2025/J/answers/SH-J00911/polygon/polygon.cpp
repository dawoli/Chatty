#include <bits/stdc++.h>
using namespace std;
bool vst[21];
int a[21];
int n;
long long ans;
void dfs(int d)
{
	if (d == n)
	{
		int max_e = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i)
			if (vst[i])
			{
				sum += a[i];
				max_e = max(max_e, a[i]);
			}
		if (sum > (max_e << 1))
			ans = (ans + 1) % 998244353;
		return;
	}
	dfs(d + 1);
	vst[d] = true;
	dfs(d + 1);
	vst[d] = false;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dfs(0);
	cout << ans;
	return 0;
}
