#include <bits/stdc++.h>
using namespace std;
int t, n;
char num[10] = {'0', '1', '2', '4', '7', '8'};
int st[10] = {6, 2, 5, 4, 3, 7};
string dp[100010], init__;
string comp(string a, string b)
{
	if(a.length() != b.length())
		return (a.length() < b.length() ? a : b);
	else
		return (a < b ? a : b);
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= 1e5 + 10; i++)
		init__ += '9';
	for(int i = 2; i <= 1e5 + 5; i++)
	{
		dp[i] = init__;
		for(int p = 0; p < 6; p++)
		{
			if(i - st[p] < 0 || i - st[p] == 1)
				continue;
			dp[i] = comp(dp[i], dp[i - st[p]] + num[p]);
		}
		dp[6] = "6";
	}
	for(int u = 1; u <= t; u++)
	{
		cin >> n;
		/**/
		if(n < 2)
			cout << -1 << endl;
		else
			cout << dp[n] << endl;
		/**
		for(int i = 1; i <= n; i++)
			cout << i << " --> " << dp[i] << " <--" << endl;
		/**/
	}
	return 0;
}

