#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5, MAXN = 5e6 + 5, base = 13331, mod = 1e9 + 7;

int n, q, len, p[MAXN], s1[N], s2[N], siz[N], t1[MAXN], t2[MAXN]; 

int turn (string s, int id)
{
	int res = 0;
	for (int i = 1; i <= siz[id]; i++)
		res = (res * base + s[i]) % mod;
	return res;
}

bool check(int id)
{
	for (int i = 1; i + siz[id] - 1 <= len; i++)
	{
		int l = i, r = i + siz[id] - 1;
		int now = (t1[r] - t1[l - 1] * p[r - l + 1] % mod + mod) % mod;
		if (now == s1[id])
		{
			int tmp = t1[len] - now * p[len - r] % mod + s2[id] * p[len - r] % mod; tmp = (tmp % mod + mod) % mod;
			if (tmp == t2[len])	
				return true;
		}
	}
	return false;
}

signed main()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 5e6; i++)
		p[i] = p[i - 1] * base % mod;
	for (int i = 1; i <= n; i++)
	{
		string sa, sb;
		cin >> sa >> sb;
		siz[i] = sa.size();
		sa = " " + sa, sb = " " + sb;
		s1[i] = turn(sa, i);
		s2[i] = turn(sb, i);
	}
	while (q--)
	{
		int res = 0;
		string ta, tb;
		cin >> ta >> tb;
		len = ta.size();
		ta = " " + ta, tb = " " + tb;
		for (int i = 1; i <= len; i++)
		{
			t1[i] = (t1[i - 1] * base + ta[i]) % mod;
			t2[i] = (t2[i - 1] * base + tb[i]) % mod; 
		}
		for (int i = 1; i <= n; i++)
			if (check(i))	res++;
		cout << res << "\n";
	}
	return 0;
}

// 17 : 47 通过小样例，时间复杂度不对，正确性存疑 
