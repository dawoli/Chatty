#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 998244353;
int n, a[5005], p[5005], f[5005], ans;
signed main()
{
	cin >> n;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {cin >> a[i]; p[i] = p[i - 1] * 2 % M;}
	sort(a + 1, a + n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + p[i - 1]) % M;
		for (int j = 0; j <= a[i]; j++) ans = ((ans - f[j]) % M + M) % M;
		for (int j = 5000; j >= 1; j--) if (j >= a[i]) f[j] += f[j - a[i]];
	}
	cout << ans;
	return 0;
}
