#include <iostream>
#include <cstdio>
using namespace std;
int A[15] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int t, n, a, b;
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n <= 14)
			cout << A[n];
		else
		{
			a = (n - 14) % 7;
			b = (n - 14) / 7;
			//cout << b << endl;
			switch (a)
			{
				case 1:
					cout << 10;
					for (int i = 1; i <= b + 1; i++) cout << 8;
					break;
				case 2:
					cout << 1;
					for (int i = 1; i <= b + 2; i++) cout << 8;
					break;
				case 3:
					cout << 200;
					for (int i = 1; i <= b; i++) cout << 8;
					break;
				case 4:
					cout << 20;
					for (int i = 1; i <= b + 1; i++) cout << 8;
					break;
				case 5:
					cout << 2;
					for (int i = 1; i <= b + 2; i++) cout << 8;
					break;
				case 6:
					cout << 6;
					for (int i = 1; i <= b + 2; i++) cout << 8;
					break;
				case 0:
					for (int i = 1; i <= b + 3; i++) cout << 8;
			}
		}
		cout << endl;
	}
	return 0;
}

