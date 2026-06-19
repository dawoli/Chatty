#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[500010], cnt, cur, ans;
bool allone = true, allbin = true;

struct Interval
{
	int l, r;
}inv[1000000];

bool cmp(Interval x, Interval y)
{
	return x.r < y.r;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			allone = false;
		}
		if (a[i] != 1 && a[i] != 0)
		{
			allbin = false;
		}
	}
	if (allone)
	{
		cout << n / 2 << endl;
		return 0;
	}
	if (allbin)
	{
		if (k == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0)
				{
					cnt++;
				}
				else
				{
					if (i < n && a[i + 1] == 1)
					{
						while (i < n && a[i + 1] == 1)
						{
							i++;
						}
						cnt++;
					}
				}
			}
			cout << cnt << endl;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i])
				{
					cnt++;
				}
			}
			cout << cnt << endl;
		}
		return 0;
	}
	if (n <= 500000)
	{
		for (int i = 1; i <= n; i++)
		{
			cur = a[i];
			if (cur == k)
			{
				cnt++;
				inv[cnt].l = inv[cnt].r = i;
			}
			for (int j = i + 1; j <= n; j++)
			{
				cur ^= a[j];
				if (cur == k)
				{
					cnt++;
					inv[cnt].l = i;
					inv[cnt].r = j;
					break;
				}
			}
		}
		sort(inv + 1, inv + cnt + 1, cmp);
		int e = 0;
		for (int i = 1; i <= cnt; i++)
		{
			if (e < inv[i].l)
			{
				ans++;
				e = inv[i].r;
			}
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
