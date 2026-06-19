#include<bits/stdc++.h>
using namespace std;
long long t, n, m, l, v, ans1, ans2;
long long d[100005], u[100005], a[100005];
long long p[100005];
bool vis[100005];
void solve1()
{
	ans1 = 0;
	ans2 = 2;
	double g;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			g = sqrt(u[i] * u[i] + 2 * a[i] * p[j]);
			if(g > v)
			{
				ans1++;
				break;
			}
		}
	}
}
void solve2()
{
	ans1 = 0;
	ans2 = 1;
	for(int i = 1; i <= n; i++)
	{
		if(u[i] > v)
		{
			ans1++;
		}
	}
	cout << ans1 << " " << ans2 << endl;
}
void solve3()
{
	ans1 = 0;
	ans2 = 1;
	double g;
	for(int i = 1; i <= n; i++)
	{
		g = sqrt(u[i] * u[i] + 2 * a[i] * l);
		if(g > v)
		{
			ans1++;
			break;
		}
	}
	cout << ans1 << " " << ans2 << endl;
}
void solve4()
{
	ans1 = 0;
	ans2 = 1;
	for(int i = 1; i <= n; i++)
	{
		if(u[i] > v)
		{
			ans1++;
		}
	}
	cout << ans1 << " " << ans2 << endl;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> l >> v;
		bool s2 = 0, s3 = 0, s4 = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> d[i] >> u[i] >> a[i];
		}
		for(int i = 1; i <= m; i++)
		{
			cin >> p[i];
		}
		for(int i = 2; i <= n; i++)
		{
			if(a[i] != 0)
			{
				s2 = 1;
				break;
			}
		}
		for(int i = 2; i <= n; i++)
		{
			if(a[i] <= 0)
			{
				s3 = 1;
				break;
			}
		}
		for(int i = 2; i <= n; i++)
		{
			if(a[i] >= 0)
			{
				s4 = 1;
				break;
			}
		}
		if(n <= 20 && m <= 20)
		{
			solve1();
		}
		else if(s2 == 0)
		{
			solve2();
		}
		else if(s3 == 0)
		{
			solve3();
		}
		else if(s4 == 0)
		{
			solve4();
		}
	}
	return 0;
}
