#include <bits/stdc++.h>
#define int128 unsigned long long
using namespace std;
const int MOD = 998244353;
int128 n, a[5001];
int128 pow (int128 n, int128 m)
{
	if (m == 1) return n;
	int128 t = pow(n, m / 2);
	if (m % 2 == 0) return t * t;
	else return t * t * n;
}
string convert (int128 x)
{
	string s;
	while (x) s += char(x % 2 + '0'), x /= 2;
	while (s.size() < n) s = s + '0'; 
	return s;
}
int128 popcount (string s)
{
	int128 cnt = 0;
	for (int i = 0; i < s.size(); i++) cnt += (s[i] == '1') ? 1 : 0; 
	return cnt;
}
int main ()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int128 cnt = 0, h = pow(2, n);
	for (int128 i = 7; i <= h; i++)
	{
		string cur = convert(i);
		if (popcount(cur) < 3)
			continue;
		else
		{
			int128 sum = 0, maxn = 0;
			for (int j = 0; j < cur.size(); j++)
				sum += (cur[j] == '1') ? a[j + 1] : 0, maxn = max(maxn, (cur[j] == '1') ? a[j + 1] : 0);
			if (sum > 2 * maxn)
				cnt++;
		}
	}
	cout << cnt % MOD;
	return 0;
} 
