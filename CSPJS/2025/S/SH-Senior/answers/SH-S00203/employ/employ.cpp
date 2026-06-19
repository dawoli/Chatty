# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 510;
const ll mod = 998244353;
ll n, m, ans;
ll c[N], t[N];
string s;

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '0') return false;
	}
	return true;
}

int main()
{
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]), t[i] = i;
	if (n <= 10)
	{
		ans = 0;
		do
		{
			ll now;
			now = 0;
			for (int i = 1; i <= n; i++)
			{
				if (c[t[i]] <= now) {now++; continue;}
				if (s[i] == '0') now++;
			}
			if (n - now >= m) ans++;
		} while (next_permutation(t + 1, t + n + 1));
		printf("%lld\n", ans);
	}
	else if (m == 1)
	{
		
	}
	else if (check())
	{
		ll cnt;
		cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (!c[i]);
		for (int i = 1; i <= cnt; i++) //后面放几个0 
		{
			//前面剩下cnt - i个0 
			
		}
		ll ans;
		ans = 1;
		for (int i = 1; i <= n - cnt; i++) ans = ans * (ll)i % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
