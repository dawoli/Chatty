#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, t, a[N], c[N], d[N];
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	int k = __lg(n) + 1;
	for (int i = 1; i <= k; i++)
		cin >> d[i];
	cin >> t;
	while(t--)
	{
		int ans = k;
		int v;
		cin >> v;
		for (int i = 1; i <= t; i++)
			ans ^= a[i];
		ans ^= v;
		cout << ans << "\n";
	}
}
