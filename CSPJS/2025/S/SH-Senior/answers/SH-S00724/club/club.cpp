#include <bits/stdc++.h>
using namespace std;

struct node
{
	int a, b, c;
};

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		node num[100010] = {};
		int cura = 0, curb = 0, curc = 0, ans = 0;
		int da[100010] = {}, db[100010] = {}, dc[100010] = {};
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i].a >> num[i].b >> num[i].c;
			int dab = abs(num[i].a - num[i].b);
			int dbc = abs(num[i].b - num[i].c);
			int dca = abs(num[i].c - num[i].a);
			int maxnum = max(max(num[i].a, num[i].b), num[i].c);
			ans += maxnum;
			if (num[i].a == maxnum)
			{
				cura++;
				da[cura] = min(dab, dca);
			}
			else if (num[i].b == maxnum)
			{
				curb++;
				db[curb] = min(dab, dbc);
			}
			else
			{
				curc++;
				dc[curc] = min(dbc, dca);
			}
		}
		sort(da + 1, da + cura + 1);
		sort(db + 1, db + curb + 1);
		sort(dc + 1, dc + curc + 1);
		if (cura > n / 2)
			for (int i = 1; i <= cura - n / 2; i++)
				ans -= da[i];
		else if (curb > n / 2)
			for (int i = 1; i <= curb - n / 2; i++)
				ans -= db[i];
		else
			for (int i = 1; i <= curc - n / 2; i++)
				ans -= dc[i];
		cout << ans << endl;
	}
	return 0;
}
