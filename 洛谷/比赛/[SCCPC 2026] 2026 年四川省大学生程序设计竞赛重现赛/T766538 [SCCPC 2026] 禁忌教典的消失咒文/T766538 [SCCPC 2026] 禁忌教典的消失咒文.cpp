// Problem URL: https://www.luogu.com.cn/problem/T766538?contestId=330334
// Finish Time: 2026/6/21 15:00:25 AC
// Start Time: 2026/6/21 14:28:50

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	vector<ll> p(n + 1, 0);
	for(int i = 1; i <= n; ++i)
	{
		if(i % 2 == 1)
		{
			p[i] = p[i - 1] + a[i];
		} else
		{
			p[i] = p[i - 1] - a[i];
		}
	}

	ll t1 = p[n] - k;
	ll t2 = p[n] + k;
	unordered_map<ll, int> odd, even;
	even[0] = 1;
	ll ans = 0;
	for(int j = 1; j <= n; ++j)
	{
		if(j % 2 == 0)
		{
			auto it = even.find(p[j] - t1);
			if(it != even.end())
				ans += it->second;
			it = odd.find(t2 - p[j]);
			if(it != odd.end())
				ans += it->second;
			even[p[j]]++;
		} 
		else
		{
			auto it = odd.find(p[j] - t1);
			if(it != odd.end())
				ans += it->second;
			it = even.find(t2 - p[j]);
			if(it != even.end())
				ans += it->second;
			odd[p[j]]++;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}