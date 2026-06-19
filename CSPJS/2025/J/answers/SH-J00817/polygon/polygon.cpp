#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5555], cnt;
bool flag = true;
void dfs(int step, int maxn, int sum)
{
	if (step > n)
	{
		if (maxn * 2 < sum)
			cnt = (cnt + 1) % mod;
		return ;
	}
	dfs(step + 1, max(maxn, a[step]), sum + a[step]);
	dfs(step + 1, maxn, sum);
	return ;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > 1)
			flag = false;
	}
	if (flag)
	{
		int p = 1;
		for (int i = 1; i <= n; i++)
			p = p * 2 % mod;
		cout << max(p - 1 - n - n * (n - 1) / 2, 0);
		return 0;
	}
	dfs(1, 0, 0);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
