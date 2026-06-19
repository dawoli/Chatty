#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ll val = n % 7;
		if (val == 0)
		{
			for (ll i = 1; i <= n / 7; i++) cout << 8;
		}
		else if (val == 1)
		{
			if (n == 1) cout << -1;
			else
			{
				cout << 10;
				for (ll i = 1; i <= n / 7 - 1; i++) cout << 8;
			}
		}
		else if (val == 2)
		{
			cout << 1;
			for (ll i = 1; i <= n / 7; i++) cout << 8;
		}
		else if (val == 3)
		{
			if (n == 3) cout << 7;
			else
			{
				cout << 22;
				for (ll i = 1; i <= n / 7 - 1; i++) cout << 8;
			}
		}
		else if (val == 4)
		{
			if (n == 4) cout << 4;
			else
			{
				cout << 20;
				for (ll i = 1; i <= n / 7 - 1; i++) cout << 8;
			}
		}
		else if (val == 5)
		{
			cout << 2;
			for (ll i = 1; i <= n / 7; i++) cout << 8;
		}
		else
		{
			cout << 6;
			for (ll i = 1; i <= n / 7; i++) cout << 8;
		}
		cout << endl;
	}
} 
