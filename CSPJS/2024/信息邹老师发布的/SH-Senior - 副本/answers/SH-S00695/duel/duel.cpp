#include<bits/stdc++.h>
using namespace std;
long long n, a[100005], ans;
bool vis[100005];
void solve1()
{
	ans = n;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(a[j] > a[i] && vis[j] == 0)
			{
				ans--;
				vis[j] = 1;
				break;
			}
		}
	}
	cout << ans;
}
void solve2()
{
	int x = 0, y = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1)
		{
			x++;
		}
		else if(a[i] == 2)
		{
			y++;
		}
	}
	if(x <= y)
	{
		ans = y;
	}
	else if(x > y)
	{
		ans = x;
	}
	cout << ans;
}
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	int g = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 1 || a[i] == 2)
		{
			g++;
		}
	}
	if(n <= 30)
	{
		solve1();
	}
	else if(g == n)
	{
		solve2();
	}
	else
	{
		solve1();
	}
	return 0;
}
