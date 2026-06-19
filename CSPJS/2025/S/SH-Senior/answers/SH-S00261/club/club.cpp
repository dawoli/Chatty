#include <bits/stdc++.h>
using namespace std;

int t, n;

struct per
{
	int a1;
	int a2;
	int a3;
}p[100005];

bool cmp(per x, per y)
{
	return x.a1 > y.a1; 
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int j = 1; j <= t; j++)
	{
		int c1[25005], c2[25005], c3[25005];
		int cnt1 = 1, cnt2 = 1, cnt3 = 1;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i].a1 >> p[i].a2 >> p[i].a3;
			int m = max(p[i].a1, max(p[i].a2, p[i].a3));
			if (m == p[i].a1)
			{
				if(cnt1 <= n / 2)
				{
					c1[cnt1] = p[i].a1;
					cnt1++;
				}
				else
				{
					if (p[i].a2 > p[i].a3)
					{
						c2[cnt2] = p[i].a2;
						cnt2++;
					}
					else
					{
						c3[cnt3] = p[i].a3;
						cnt3++;
					}
				}
			}
			else if (m == p[i].a2)
			{
				if(cnt2 <= n / 2)
				{
					c2[cnt2] = p[i].a2;
					cnt2++;
				}
				else
				{
					if (p[i].a1 > p[i].a3)
					{
						c1[cnt1] = p[i].a1;
						cnt1++;
					}
					else
					{
						c3[cnt3] = p[i].a3;
						cnt3++;
					}
				}
			}
			else
			{
				if(cnt3 <= n / 2)
				{
					c3[cnt3] = p[i].a3;
					cnt3++;
				}
				else
				{
					if (p[i].a1 > p[i].a2)
					{
						c1[cnt1] = p[i].a1;
						cnt1++;
					}
					else
					{
						c2[cnt2] = p[i].a2;
						cnt2++;
					}
				}
			}
		}
		int ans = 0;
		if(cnt2 == 1)
		{
			sort(p + 1, p + n + 1, cmp);
			for (int j = 1; j <= n / 2; j++) ans += c1[j];
			cout << ans << endl;
			continue; 
		}
		for (int j = 1; j <= cnt1 - 1; j++) ans += c1[j];
		for (int j = 1; j <= cnt2 - 1; j++) ans += c2[j];
		for (int j = 1; j <= cnt3 - 1; j++) ans += c3[j];
		cout << ans << endl;
	}
	return 0; 
} 
