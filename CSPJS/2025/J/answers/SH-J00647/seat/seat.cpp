#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, m, a[1005], x;
int main()
{ 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	x = a[1];
	for (int i = 2; i <= n * m; i++) cin >> a[i];
	sort(a + 1, a + 1 + n * m, greater <int> ());
	for (int i = 1; i <= n; i++)
	{ 
		for (int j = 1; j <= m; j++)
		{
			if (a[(i - 1) * m + j] == x)
			{
				cout << i << ' ' << (i % 2 == 1 ? j :(m - j + 1));
				return 0; 
			}
		}
	}
	return 0;
}
