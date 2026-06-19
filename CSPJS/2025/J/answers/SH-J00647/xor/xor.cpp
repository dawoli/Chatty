#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n, k, a[500005];
ll sum[500005];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool flag = true, bflag = true;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		if (a[i] != 1) flag = false;
		if (a[i] > 1) bflag = false;
	}
	//特判：特殊性质a, 特殊性质b, 共计6/20个测试点, 共计30/100分 
	if (flag && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	if (bflag && k == 1)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1) ans++;
		}
		cout << ans;
		return 0;
	}
	if (bflag && k == 0)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0) ans++;
			else
			{
				if (a[i + 1] == 1) i++, ans++;
			}
		}
		cout << ans;
		return 0;
	}
	//暴力贪心，大致能拿10~20/100分 
	ll l = 1, r = 0, cnt = 0;
	while (l <= n)
	{
		r++;
		if (sum[r] ^ sum[l - 1] == k)
		{
			l = r + 1;
			r = l;
			cnt++;
		}
		while (sum[r] ^ sum[l - 1] == 0)
		{
			l = r + 1;
			r = l;
		}
		if (r > n)
		{
			l++;
			r = l;
		}
	}
	cout << cnt;
	return 0;
}
