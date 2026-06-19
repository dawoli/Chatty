// Problem URL: https://iai.sh.cn/problem/1243
// Finish Time: 2026/5/23 17:59:31 WA
// Start Time: 2026/5/23 17:15:32
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, t, a[41];
ll ans = LLONG_MIN;
bitset<40> lb, rb;
vector<ll> lt, rt;
void sum(int l, int r)
{
	if(l > r)
		return;
	int mid = (l + r) >> 1;
	sum(l, mid);
	sum(mid + 1, r);
	for(int i = 0; i < (1 << (mid - l + 1)); i++)
	{
		ll s = 0;
		for(int j = 0; j <= mid - l; j++)
			if(i & (1 << j))
				s += a[l + j];
		if(s <= t)
			lt.push_back(s);
	}
	for(int i = 0; i < (1 << (r - mid)); i++)
	{
		ll s = 0;
		for(int j = 0; j < r - mid; j++)
			if(i & (1 << j))
				s += a[mid + 1 + j];
		if(s <= t)
			rt.push_back(s);
	}
	sort(rt.begin(), rt.end(), greater<ll>());
	sort(lt.begin(), lt.end());
	for(size_t i = 0; i < rt.size(); i++)
	{
		auto pos = upper_bound(lt.begin(), lt.end(), t - rt[i]);
		if(pos != lt.begin())
		{
			--pos;
			ans = max(ans, rt[i] + *pos);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sum(1, n);
	cout << ans;
	return 0;
}