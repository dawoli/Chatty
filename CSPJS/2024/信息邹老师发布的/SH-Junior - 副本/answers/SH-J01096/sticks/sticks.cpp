#include <bits/stdc++.h>
using namespace std;
int t, n;
map <int, int> mp;
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n >= 7)
		{
			int x = n / 7;
			n %= 7;
			if (n == 0)
			{
				for (int i = 1; i <= x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
			if (n == 1)
			{
				cout << 10;
				for (int i = 1; i < x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
			if (n == 2)
			{
				cout << 1;
				for (int i = 1; i <= x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
			if (n == 3)
			{
				cout << 22;
				for (int i = 1; i < x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
			if (n == 4)
			{
				cout << 20;
				for (int i = 1; i < x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
			if (n == 5)
			{
				cout << 2;
				for (int i = 1; i <= x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
			if (n == 6)
			{
				cout << 6;
				for (int i = 1; i <= x; i++)
				{
					cout << 8;
				}
				cout << endl;
				continue;
			}
		}
		else if (n < 7)
		{
			if (n == 0)
			{
				cout << -1 << endl;
			}
			if (n == 1)
			{
				cout << -1 << endl;
			}
			if (n == 2) 
			{
				cout << 1 << endl;
			}
			if (n == 3)
			{
				cout << 7 << endl;
			}
			if (n == 4)
			{
				cout << 4 << endl;
			}
			if (n == 5)
			{
				cout << 2 << endl;
			}
			if (n == 6)
			{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
