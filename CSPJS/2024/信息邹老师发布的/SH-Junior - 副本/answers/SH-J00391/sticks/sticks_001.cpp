#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << -1 << endl;
		}
		else
		{
			string ans = "";
			if (n % 7 == 1)
			{
				ans += '1';
				ans += '0';
			}
			for (int i = 0; i < n / 7; ++i)
			{
				ans += "8";
			}
			cout << ans << endl;
		}
	}
	return 0;
}
