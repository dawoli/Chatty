#include<bits/stdc++.h>
using namespace std;
int n, a[100005], b[100005], ans, flag, j;
map<int, int> mp;
int solve1()
{
	ans = mp[2] + max(0, mp[1] - mp[2]);
}
int solve2()
{
	for(int i = 2; i < j; i ++)
	{
		ans = max(0, ans + (mp[b[i]] - mp[b[i + 1]]));
	}
	ans += mp[b[j]];
}
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		mp[a[i]] ++;
		if(a[i] > 2)
		{
			flag = 1;
		}
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i ++)
	{
		int j = 0;
		if(a[i] != a[i + 1])
		{
			b[j] = a[i];
		}
	}
	if(flag == 0)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	cout << ans;
	return 0;
}
