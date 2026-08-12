// Problem URL: https://www.luogu.com.cn/problem/P1651
// Finish Time: 2026/8/11 16:41:45 AC
// Finish Time: 2026/8/11 16:08:27 WA/RE 40pts
// Start Time: 2026/8/11 15:53:58

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
const int		  MAXN = 50;

int n, h[MAXN], f[2][1000001], sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		sum += h[i];
	}
	memset(f, -0x3f3f3f3f, sizeof(f));
	f[0][500000] = 0;
	int ans		 = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 1000000; j++)
		{
			f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][j]);
			if (j - h[i] >= 0)
				f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][j - h[i]] + h[i]);
			if (j + h[i] <= 1000000)
				f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][j + h[i]]);
			if (j == 500000)
				ans = max(ans, f[i & 1][j]);
		}
	}
	cout << (ans == 0 ? -1 : ans) << endl;
	return 0;
}