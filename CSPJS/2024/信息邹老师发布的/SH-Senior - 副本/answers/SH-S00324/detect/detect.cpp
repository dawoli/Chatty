#include<bits/stdc++.h>
using namespace std;
int t, n, m, l, V, d[100005], v[100005], a[100005], q[100005], flag1, flag2;
int ans1, ans2, s[100005], ti;
map<int, int> mp;
void solve1()
{
	for(int i = 1; i <= n; i ++)
	{
		if(v[i] > V)
		{
			ans1++;
		}
	}
	ans2 = m - 1;
}
void solve2()
{
	for(int i = 1; i <= n; i ++)
	{
		if(v[i] > V)
		{
			ans1++;
			s[i] = d[i] + (V - v[i]) * (V - v[i]) / a[i] / 2;
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(q[j] > s[i])
			{
				mp[j]++;
				break;
			}
		}
	}
	ans2 = m;
	for(int i = 1; i <= m; i ++)
	{
		if(mp[i] != 0)
		{
			ans2--;
		}
	}
}
void solve3()
{
	for(int i = 1; i <= n; i ++)
	{
		ti = sqrt(2 * a[i] * (l - d[i]));
		if(ti * a[i] > V)
		{
			s[i] = d[i] + (V - v[i]) * (V - v[i]) / a[i] / 2;
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			if(q[j] > s[i])
			{
				mp[j]++;
				break;
			}
		}
	}
	ans2 = m;
	for(int i = 1; i <= m; i ++)
	{
		if(mp[i] != 0)
		{
			ans2--;
		}
	}
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	cin >> t;
	for(int e = 1; e <= t; e ++)
	{
		cin >> n >> m >> l >> V;
		for(int i = 1; i <= n; i ++)
		{
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] != 0)
			{
				flag1 = 1;
			}
			if(a[i] >= 0)
			{
				flag2 = 1;
			}
		}
		for(int i = 1; i <= m; i ++)
		{
			cin >> q[i];
		}
		if(flag1 == 0)
		{
			solve1();
		}
		else if(flag2 == 0)
		{
			solve2();
		}
		else
		{
			solve3();
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
