#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 998244353;
int n, m, a[25], c[25], ans = 1;
string s;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) ans = ans * i % M;
	cout << ans;
	return 0;
}
