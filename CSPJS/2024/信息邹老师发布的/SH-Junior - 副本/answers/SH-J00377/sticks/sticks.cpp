#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
int a[] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28};
int b[] = {68, 88, 108, 188, 200, 208, 288};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		if (n <= 12)
			cout << a[n] << endl;
		else 
		{
			n -= 13;
			cout << b[n % 7];
			for (int i = 1; i <= n / 7; i++)
				cout << 8;
		}
	}
}
