//prepare
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
// prepare
#include <algorithm>

constexpr int MAXN = 1e5 + 5;

int n, r[MAXN], c[MAXN], u[MAXN], die_last = 0;

int main() 
{
    cin.tie(nullptr) -> sync_with_stdio(false);
#ifndef DEBUG
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
#endif
	cin >> n;
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
		if (!c[r[i]])
			t++;
		c[r[i]]++, u[r[i]]++;
	}
	std::unique(r+1, r+n+1);
	n = t;
	std::sort(r+1, r+1+n);
	for (int i = 2; i <= n; ++i)
	{
		for (int j = die_last+1; j < i and u[r[i]]; ++j)
		{
			int sub = std::min(c[r[j]], u[r[i]]);
			c[r[j]] -= sub;
			if (!c[r[j]])
				die_last++;
			u[r[i]] -= sub;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += c[r[i]];
	cout << ans << endl;
#ifndef DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
	return 0;
}
