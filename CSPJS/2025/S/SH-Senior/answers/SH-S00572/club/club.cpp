#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int t, n, a[100005][6], cnt[5], ans;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		
		cin >> n;
		ans = 0;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			for (int j = 1; j <= 3; j++)
			{
				if (max({a[i][1], a[i][2], a[i][3]}) == a[i][j] && a[i][4] == 0)
				{
					a[i][4] = j;
					cnt[j]++;
				}
			}
			ans += max({a[i][1], a[i][2], a[i][3]});
		}
		bool f;
		f = 0;
		int minx = 0x3f3f3f3f, mini = -1;
		for (int i = 1; i <= 3; i++)
		{
			while (cnt[i] > n / 2)
			{
				f = 1;
				for (int j = 1; j <= n; j++)
				{
					if (a[j][i] < minx)
					{
						minx = a[j][i], mini = j;
					}
				}
				int tmp;
				if (i == 1)
				{
					a[mini][4] = max(a[mini][2], a[mini][3]);
					tmp = (a[mini][4] == a[mini][2] ? 2 : 3);
				}
				else if (i == 2)
				{
					a[mini][4] = max(a[mini][1], a[mini][3]);
					tmp = (a[mini][4] == a[mini][1] ? 1 : 3);
				}
				else if (i == 3)
				{
					a[mini][4] = max(a[mini][1], a[mini][2]);
					tmp = (a[mini][4] == a[mini][1] ? 1 : 2);
				}
				cnt[i]--;
				cnt[tmp]++;
				ans += a[mini][4] - a[mini][i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
