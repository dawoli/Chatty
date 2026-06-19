#include <bits/stdc++.h>
using namespace std;
int t, n, a[200010], tmp, p[200010], m, ans1, ans, flag;
void solve1()
{
	ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		tmp = i;
		m = ans1 = 0;
		for (int j = 1; j <= n; j++)
		{
			p[j] = tmp / (1 << (n - j));
			tmp -= p[j] * (1 << (n - j));
		}
//		cout << "i=" << i << endl;
//		for (int j = 1; j <= n; j++) cout << p[j] << " ";
//		cout << endl;
//		for (int j = 1; j <= n; j++) cout << a[j] << " ";
//		cout << endl;
		for (int j = 1; j <= n; j++)
		{
			tmp = flag = 0;
			for (int k = j - 1; k >= 1; k--) if (p[k] == p[j]) {flag = 1; tmp = k; break;}
			if (not flag) continue;
			if (a[tmp] == a[j]) ans1 += a[tmp];
		}
//		cout << "ans1=" << ans1 << endl;
		ans = max(ans, ans1);
	}
	cout << ans << endl;
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++) cin >> a[j];
		if (n <= 15) solve1();
	}
	return 0;
}
