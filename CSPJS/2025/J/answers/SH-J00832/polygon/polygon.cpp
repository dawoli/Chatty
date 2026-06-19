#include <iostream>
using namespace std;

const int MOD = 998244353;
int n, a[5010], c[5010], cnt, maxn, sum, ans;
bool allone = true;

int comb(int a, int b)
{
	if (a - b < b)
	{
		b = a - b;
	}
	int mul = 1;
	for (int i = 1; i <= b; i++)
	{
		mul *= (a - i + 1);
		mul %= MOD;
	}
	for (int i = 1; i <= b; i++)
	{
		mul /= i;
	}
	return mul;
}

void dfs(int step)
{
	if (step > n)
	{
		cnt = 0;
		maxn = 0;
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[i])
			{
				cnt++;
				maxn = max(maxn, a[i]);
				sum += a[i];
			}
		}
		if (cnt >= 3 && sum > maxn * 2)
		{
			ans++;
			ans %= MOD;
		}
		return;
	}
	c[step] = 1;
	dfs(step + 1);
	c[step] = 0;
	dfs(step + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			allone = false;
		}
	}
	if (n <= 20)
	{
		dfs(1);
		cout << ans << endl;
		return 0;
	}
	if (allone)
	{
		for (int i = 3; i <= n; i++)
		{
			ans += comb(n, i);
			ans %= MOD;
		}
		cout << ans << endl;
		return 0;
	} 
	return 0;
}
