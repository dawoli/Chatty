#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n, m;

inline int exgcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a%b, y, x);
	y -= a / b * x ;
	return d;
}

inline inv(int a, int p = mod)
{
	int x, y;
	exgcd(a, p, x, y);
	return (x % p + p) % p;
}

inline int C(int a, int b)
{
	int x = 1, y = 1, z = 1;
	for (int i = 1; i <= a; i++)
		x = x * i % mod;
	for (int i = 1; i <= b; i++)
		y = y * i % mod;
	for (int i = 1; i <= (a-b); i++)
		z = z * i % mod;
	return x * inv(y) % mod * inv(z) % mod;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1')
			cnt++;
	int ans = 0;
	for (int i = m; i <= cnt; i++)
	{
		ans = (ans + C(i, m)) % mod;
	}
	cout << ans << '\n';
	return 0;
}
