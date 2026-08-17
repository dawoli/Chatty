// Problem URL: https://www.luogu.com.cn/P4549
// Finish Time: 2026/8/12 15:24:54 AC
// Start Time: 2026/8/12 15:13:03

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 2e1 + 1;

int n, a[MAXN], ans = -1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 2)
			ans = __gcd(abs(a[1]), abs(a[2]));
		else
			ans = __gcd(ans, abs(a[i]));
	}
	cout << (ans == -1 ? abs(a[1]) : ans);
	return 0;
}