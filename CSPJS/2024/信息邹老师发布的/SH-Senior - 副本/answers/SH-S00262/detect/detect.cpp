#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int t;

void Work()
{
	int n, m, l, maxv;
	int d, v, a, p[MAXN] = {0}, st[MAXN], en[MAXN], t[MAXN] = {0};
	int ans1 = 0, ans2 = 0;
	cin >> n >> m >> l >> maxv;
	for (int i = 1; i <= n; i++)
	{
		cin >> d >> v >> a;
		if (a < 0)
		{
			if (v <= maxv)
			{
				st[i] = -1;
				en[i] = -1;
			}
			else
			{
				st[i] = d;	//º¬ 
				en[i] = d + ceil((double)(maxv * maxv - v * v) / (2 * a));	//²»º¬ 
			}
		}
		else if (a > 0)
		{
			st[i] = d + ceil((double)(maxv * maxv - v * v) / (2 * a));	//º¬
			en[i] = l + 1;	//²»º¬ 
			if (st[i] > l)
			{
				st[i] = -1;
				en[i] = -1;
			}
		}
		else
		{
			if (v <= maxv)
			{
				st[i] = -1;
				en[i] = -1;
			}
			else
			{
				st[i] = d;	//º¬ 
				en[i] = l + 1;	//²»º¬ 
			}
		}
//		cout << st[i] << ' ' << en[i] << endl;
	}
	map<int, bool> mp;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i];
		mp[p[i]] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = st[i]; j < en[i]; j++)
		{
			if (mp[j])
			{
				t[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (t[i]) ans1++;
	}
	cout << ans1 << " " << ans1 << endl;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) Work();
	return 0;
}
