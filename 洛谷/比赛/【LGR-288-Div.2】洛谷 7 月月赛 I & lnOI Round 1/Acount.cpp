// Problem URL: https://www.luogu.com.cn/problem/T710248?contestId=297106
// Start Time: 2026/7/11 17:13:35

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lowbit(ll x)
{
	return x & -x;
}

int n;
ll	x, k;

int _main(int n)
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	for (int i = 2 << (n - 1); i >= 1; i--)
	{
		x = i;
		k = __builtin_popcountll(x);
		if (lowbit(x) == 2LL << (k - 1))
		{
			return x;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("A.out", "w", stdout);
	for (int i = 1; i <= 20; i++)
	{
		cout << _main(2 * i) << ", ";
	}
	return 0;
}