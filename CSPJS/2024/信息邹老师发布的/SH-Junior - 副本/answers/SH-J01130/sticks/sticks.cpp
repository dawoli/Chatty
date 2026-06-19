#include <bits/stdc++.h>
using namespace std;
int num(int n)
{
	switch(n)
	{
		case 1: return 2;
		case 7: return 3;
		case 4: return 4;
		case 2: case 3: case 5: return 5;
		case 0: case 6: case 9: return 6;
		case 8: return 7;
		default:
			return num(n % 10) + num(n / 10);
	}
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n <= 1)
		{
			cout << -1 << endl;
			continue;
		}
		if (n <= 7)
		{
			if (n == 2) cout << 1 << endl;
			if (n == 3) cout << 7 << endl;
			if (n == 4) cout << 4 << endl;
			if (n == 5) cout << 2 << endl;
			if (n == 6) cout << 6 << endl;
			if (n == 7) cout << 8 << endl;
		}
		else
		{
			int m = n % 7, p;
			if (m == 0)
			{
				for (int i = 0; i < n / 7; i++)
				{
					cout << 8;
				}
				cout << endl;
			}
			else
			{
				m += 7;
				n /= 7;
				n *= 7;
				n -= 7;
				for (int i = 10; i <= 99; i++)
				{
					if (num(i) == m)
					{
						p = i;
						break;
					}
				}
				cout << p;
				for (int i = 0; i < n / 7; i++)
				{
					cout << 8;
				}
				cout << endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
