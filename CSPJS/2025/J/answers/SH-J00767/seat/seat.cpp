#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, a[15][15], l[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> l[i];
	}
	int flag = l[1];
	sort(l + 1, l + n*m + 1);
	for (int i = 1; i <= n*m; i++)
	{
		if (l[i] == flag)
		{
			int x = n*m - i + 1;
//			cout << x << "\n";
			int ans1 = (x + n - 1) / n;
			int ans2 = (x - 1) % n + 1;
			if (ans1 % 2 == 0) ans2 = n - ans2 + 1;
			cout << ans1 << " " << ans2 << "\n";
			return 0;
		} 
	}
 } 
