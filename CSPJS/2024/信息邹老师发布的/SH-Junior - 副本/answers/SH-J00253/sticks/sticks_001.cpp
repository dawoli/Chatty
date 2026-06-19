#include <bits/stdc++.h>
using namespace std;

int t;

void Work()
{
	int n;
	cin >> n;
	if (n == 1) cout << -1;
	else if (n == 3) cout << 7;
	else if (n == 4) cout << 4;
	else if (n % 7 == 0)
	{
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	else if (n % 7 == 1)
	{
		cout << 10;
		n -= 8;
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	else if (n % 7 == 2)
	{
		cout << 1;
		n -= 2;
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	else if (n % 7 == 3)
	{
		cout << 22;
		n -= 10;
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	else if (n % 7 == 4)
	{
		cout << 20;
		n -= 11;
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	else if (n % 7 == 5)
	{
		cout << 2;
		n -= 5;
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	else if (n % 7 == 6)
	{
		cout << 6;
		n -= 6;
		while (n)
		{
			cout << 8;
			n -= 7;
		}
	}
	cout << endl;
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) Work();
	return 0;
}
