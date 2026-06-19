#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int mmx0, mmy0, mmd0, mmn, mmm, mmk;
		cin >> mmn >> mmm >> mmk;
		cin >> mmx0 >> mmy0 >> mmd0;
		for (int i = 1; i <= mmn; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < mmm; j++)
			{
				if (s[j] == '.')
					a[i][j + 1] = 0;
				if (s[j] == 'x')
					a[i][j + 1] = -1;
			}
		}
		a[mmx0][mmy0] = 1;
		for (int i = 1; i <= mmk; i++)
		{
			bool walk = false;
			if (mmd0 == 0 && mmy0 + 1 <= mmm && a[mmx0][mmy0 + 1] != -1)
			{
				a[mmx0][mmy0 + 1] = 1;
				mmy0 += 1;
				walk = true;
			}
			else if (mmd0 == 2 && mmy0 - 1 >= 1 && a[mmx0][mmy0 - 1] != -1)
			{
				a[mmx0][mmy0 - 1] = 1;
				mmy0 -= 1;
				walk = true;
			}
			else if (mmd0 == 3 && mmx0 - 1 >= 1 && a[mmx0 - 1][mmy0] != -1)
			{
				a[mmx0 - 1][mmy0] = 1;
				mmx0 -= 1;
				walk = true;
			}
			else if (mmd0 == 1 && mmx0 + 1 <= mmn && a[mmx0 + 1][mmy0] != -1)
			{
				a[mmx0 + 1][mmy0] = 1;
				mmx0 += 1;
				walk = true;
			}
			if (walk == false)
			{
				mmd0 += 1;
				mmd0 %= 4;
			}
			a[mmx0][mmy0] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= mmn; i++)
		{
			for (int j = 1; j <= mmm; j++)
			{
				if (a[i][j] == 1)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
