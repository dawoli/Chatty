#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve()
{
	int n;
	ull k;
	cin >> n >> k;
	vector<ull> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<ull> cur = a;
	vector<ull> b(n, 0);
	ull rem = k;
	ull or_val = 0;
	for (ull x : cur) or_val |= x;

	for (int bit = 59; bit >= 0; --bit)
	{
		if ((or_val >> bit) & 1) continue;
		ull min_d = ULLONG_MAX;
		int best =-1;
		for (int i = 0; i < n; ++i)
		{
			ull x = cur[i];
			ull target = ((x >> bit) + 1) << bit;
			ull d = target - x;
			if (d < min_d)
			{
				min_d = d;
				best = i;
			}
		}
		if (min_d <= rem)
		{
			cur[best] += min_d;
			b[best] += min_d;
			rem -= min_d;
			or_val |= cur[best];
		}
	}

	for (int i = 0; i<n && rem> 0; ++i)
	{
		ull space = or_val - cur[i];
		ull add = min(rem, space);
		cur[i] += add;
		b[i] += add;
		rem -= add;
	}

	cout << or_val <<  '\n';
	for (int i = 0; i < n; ++i)
	cout << b[i] <<  " \n"[i == n - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}