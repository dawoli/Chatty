#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, s[10] = {0, 2, 3, 4, 5, 6, 7};
string minn[10] = {"", "", "1", "7", "4", "2", "0", "8"};
string dp[N], INF = "";
string f[N];
void cal(string s, int n, int i)
{
	cout << s;
	int cnt = (n - i) / 7;
	for (int i = 1; i <= cnt; i++)
	{
		cout << "8";
	}
	cout << '\n';
	return ;
 } 
bool _min(string a, string b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}
void solve()
{
	for (int i = 1; i <= 1e5 + 5; i++)
	{
		dp[i] = INF; 
	}
	cin >> n;
	if (f[n] != "")
	{
		cout << f[n] << endl;
		return ;
	}
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	for (int i = 8; i <= n; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (i - s[j] <= 0) break;
			if (dp[i - s[j]] == INF) continue;
			if (_min(dp[i - s[j]] + minn[s[j]], dp[i])) dp[i] = dp[i - s[j]] + minn[s[j]];
		}
		if (dp[i] != INF && (n - i) % 7 == 0 && n > 900)
		{
			cal(dp[i], n, i);
			return ;
		}
	}
	if (dp[n] == INF)
	{
		cout << -1 << endl;
		f[n] = "-1";
	}
	else 
	{
		cout << dp[n] << endl;
		f[n] = dp[n];
	}
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	for (int i = 1; i <= 5e4 + 1; i++)
	{
		INF += "1";
	}
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
