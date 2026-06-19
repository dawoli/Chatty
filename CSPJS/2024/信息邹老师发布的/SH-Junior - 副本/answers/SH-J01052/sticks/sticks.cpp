#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	for (int i=1; i<=t; i++)
	{
		int n;
		cin >> n;
		if (n <= 1)
			cout << -1 << endl;
		else if (n >= 7)
		{
			if (n % 7 == 0)
			{
				for (int j=1; j<=n/7; j++)
					cout << 8;
				cout << endl;
			}
			else if (n % 7 == 1)
			{
				cout << 1 << 0;
				for (int j=1; j<=(n-8)/7; j++)
					cout << 8;
				cout << endl;
			}
			else if (n % 7 == 2)
			{
				cout << 3 << 4;
				for (int j=1; j<=(n-9)/7; j++)
					cout << 8;
				cout << endl;
			}
			else if (n % 7 == 3)
			{
				cout << 2 << 3;
				for (int j=1; j<=(n-10)/7; j++)
					cout << 8;
				cout << endl;
			}
			else if (n % 7 == 4)
			{
				cout << 2 << 0;
				for (int j=1; j<=(n-11)/7; j++)
					cout << 8;
				cout << endl;
			}
			else if (n % 7 == 5)
			{
				cout << 2;
				for (int j=1; j<=(n-5)/7; j++)
					cout << 8;
				cout << endl;
			}
			else if (n % 7 == 6)
			{
				cout << 6;
				for (int j=1; j<=(n-6)/7; j++)
					cout << 8;
				cout << endl;
			}
		}
		else
		{
			if (n == 2) cout << 1 << endl;
			if (n == 3) cout << 7 << endl;
			if (n == 4) cout << 4 << endl;
			if (n == 5) cout << 2 << endl;
			if (n == 6) cout << 6 << endl;
		}
	}
	return 0;
}
