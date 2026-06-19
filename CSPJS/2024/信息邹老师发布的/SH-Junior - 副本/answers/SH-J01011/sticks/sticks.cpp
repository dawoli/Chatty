#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[7] = {88, 108, 188, 200, 208, 288, 688}; 
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 1)
			cout << -1;
		else if (n == 2)
			cout << 1;
		else if (n == 3)
			cout << 7;
		else if (n == 4)
			cout << 4;
		else if (n == 5)
			cout << 2;
		else if (n == 6)
			cout << 6;
		else if (n == 7)
			cout << 8;
		else if (n == 8)
			cout << 10;
		else if (n == 9)
			cout << 18;
		else if (n == 10)
			cout << 22;
		else if (n == 11)
			cout << 20;
		else if (n == 12)
			cout << 28;
		else if (n == 13)
			cout << 68;
		else
			cout << a[n % 7] << string(n / 7 - 2, '8');
		cout << endl;
	}
	return 0;
}
