#include <bits/stdc++.h>
using namespace std;
int t, n, ans, a[200005], f[105][105][2], d[200005][11][2];
bool b[1000005];
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (b[a[i]]) ans++;
			b[a[i]++];
//			if (n <= 100)
//			{
//				for (int j = 0; j < i - 1; j++)
//					f[i][j][0] = f[i - 1][j][0] + (a[i] == a[i - 1]) * a[i];
//				for (int j = 0; j < i - 1; j++)
//					f[i][i - 1][0] = f[i - 1][j][1] + (a[i] == a[j]) * a[i];
//				for (int j = 0; j < i - 1; j++)
//					f[i][j][1] = f[i - 1][j][1] + (a[i] == a[i - 1]) * a[i];
//				for (int j = 0; j < i - 1; j++)
//					f[i][i - 1][1] = f[i - 1][j][0] + (a[i] == a[j]) * a[i];
//				if (i == i)
//				{
//					for (int j = 0; j <= i - 1; j++)
//					{
//						cout << f[i][j][0] << "," << f[i][j][1] << " ";
//						ans = max(max(ans, f[i][j][0]), f[i][j][1]);
//					}
//					cout << endl;
//				}
//			}
			
		}
		cout << ans << endl;
	}
}
