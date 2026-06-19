#include <bits/stdc++.h>
using namespace std;
int t, n, ans[20] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		if (n <= 14) cout << ans[n];
		else
		{
			if (n % 7 == 1)
			{
				cout << 10;
				for (int i = 1; i <= n / 7 - 1; i++) cout << 8;
			}
			if (n % 7 == 2)
			{
				cout << 1;
				for (int i = 1; i <= n / 7; i++) cout << 8;
			}
			if (n % 7 == 3)
			{
				cout << 22;
				for (int i = 1; i <= n / 7 - 1; i++) cout << 8;
			}
			if (n % 7 == 4)
			{
				cout << 20;
				for (int i = 1; i <= n / 7 - 1; i++) cout << 8;
			}
			if (n % 7 == 5)
			{
				cout << 2;
				for (int i = 1; i <= n / 7; i++) cout << 8;
			} 
			if (n % 7 == 6)
			{
				cout << 6;
				for (int i = 1; i <= n / 7; i++) cout << 8;
			}
			if (n % 7 == 0)
			{
				for (int i = 1; i <= n / 7; i++) cout << 8;
			}
		}
		cout << endl;
	}
	return 0;
}
