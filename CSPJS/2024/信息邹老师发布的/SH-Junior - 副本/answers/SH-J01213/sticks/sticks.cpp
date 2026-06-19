#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int f[] = {108,188,200,208,288,688,888};
int g[] = {15, 16, 17, 18, 19, 20, 21};

signed main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x <= 14) cout << dp[x];
		else
		{
			cout << f[(x - 1) % 7];
			x -= g[(x - 1) % 7];
			while (x > 0)
			{
				cout << '8';
				x -= 7;
			}
		}
		cout << endl;
	}
	return 0;
}
