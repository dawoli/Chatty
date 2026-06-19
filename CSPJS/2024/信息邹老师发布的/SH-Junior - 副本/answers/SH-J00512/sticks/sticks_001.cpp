#include <bits/stdc++.h>
using namespace std;
int t, n, a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans = 1, ans2, cnt;
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n < 2) cout << -1;
		else if (n == 2) cout << 1;
		else if (n == 6) cout << 6;
		else if (n == 18) cout << 208;
		else if (n % 7 == 0)
		{
			for (int i = 1; i <= n / 7; i++)
				cout << "8";
		}
		else if (n % 7 == 1)
		{
			cout << "10";
			for (int i = 1; i <= n / 7 - 1; i++)
				cout << "8";
		}
		else
		{
			bool f = 0;
			while (ans <= 0.11112 * pow(10, (n + 1) / 2))
			{
				ans++;
				ans2 = ans;
				cnt = 0;
				f = 0;
				while (ans2)
				{
					cnt += a[ans2 % 10];
					ans2 /= 10;
				}
				if (cnt == n)
				{
					cout << ans;
					f = 1;
					break;
				}
			}
			if (!f) cout << -1;
		}
		cout << "\n";
	}
	return 0;
}
