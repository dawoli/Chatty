#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct Member
{
	int s1, s2, s3;
	int mx;
} a[100005];
bool cmp(Member x, Member y)
{
	if (x.mx != y.mx)
		return x.mx < y.mx;
	if (x.mx == 1)
	{
		int dx, dy;
		if (x.s2 > x.s3)
			dx = x.s1 - x.s2;
		else
			dx = x.s1 - x.s3;
		if (y.s2 > y.s3)
			dy = y.s1 - y.s2;
		else
			dy = y.s1 - y.s3;
		return dx > dy;
	}
	if (x.mx == 2)
	{
		int dx, dy;
		if (x.s1 > x.s3)
			dx = x.s2 - x.s1;
		else
			dx = x.s2 - x.s3;
		if (y.s1 > y.s3)
			dy = y.s2 - y.s1;
		else
			dy = y.s2 - y.s3;
		return dx > dy;
	}
	if (x.mx == 3)
	{
		int dx, dy;
		if (x.s1 > x.s2)
			dx = x.s3 - x.s1;
		else
			dx = x.s3 - x.s2;
		if (y.s1 > y.s2)
			dy = y.s3 - y.s1;
		else
			dy = y.s3 - y.s2;
		return dx > dy;
	}
	return 0;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].s1, &a[i].s2, &a[i].s3);
			if (a[i].s1 >= a[i].s2 && a[i].s1 >= a[i].s3)
				a[i].mx = 1;
			if (a[i].s2 >= a[i].s1 && a[i].s2 >= a[i].s3)
				a[i].mx = 2;
			if (a[i].s3 >= a[i].s1 && a[i].s3 >= a[i].s2)
				a[i].mx = 3;
		}
		sort(a + 1, a + n + 1, cmp);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].mx == 1)
			{
				if (cnt1 < n / 2)
					cnt1++, sum += a[i].s1;
				else
				{
					if (a[i].s2 >= a[i].s3)
						cnt2++, sum += a[i].s2;
					else
						cnt3++, sum += a[i].s3;
				}
			}
			if (a[i].mx == 2)
			{
				if (cnt2 < n / 2)
					cnt2++, sum += a[i].s2;
				else
				{
					if (a[i].s1 >= a[i].s3)
						cnt1++, sum += a[i].s1;
					else
						cnt3++, sum += a[i].s3;
				}
			}
			if (a[i].mx == 3)
			{
				if (cnt3 < n / 2)
					cnt3++, sum += a[i].s3;
				else
				{
					if (a[i].s1 >= a[i].s2)
						cnt1++, sum += a[i].s1;
					else
						cnt2++, sum += a[i].s2;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
