#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t,n,a[N][4],b[N];
int f[105][105][105];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n;
		int ans = 0,m = n / 2;
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= 3;k++)
				cin >> a[j][k];
		if (n <= 200)
		{
			for (int j = 0;j <= m;j++)
				for (int k = 0;k <= m;k++)
					for (int l = 0;l <= m && j + k + l <= n;l++)
					{
						if (j != 0)
							f[j][k][l] = max(f[j][k][l],f[j - 1][k][l] + a[j + k + l][1]);
						if (k != 0)
							f[j][k][l] = max(f[j][k][l],f[j][k - 1][l] + a[j + k + l][2]);
						if (l != 0)
							f[j][k][l] = max(f[j][k][l],f[j][k][l - 1] + a[j + k + l][3]);
					}
			for (int j = 0;j <= m;j++)
				for (int k = 0;k <= m;k++)
					if (n - j - k <= m)
						ans = max(ans,f[j][k][n - j - k]);
		}
		else
		{
			for (int j = 1;j <= n;j++)
				b[j] = a[j][1];
			sort(b + 1,b + n + 1);
			for (int j = m + 1;j <= n;j++)
				ans += b[j];	
		}
		cout << ans << endl;
	}
	return 0;
}
