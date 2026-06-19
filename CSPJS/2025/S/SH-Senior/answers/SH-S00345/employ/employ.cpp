#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, mod = 998244353;
ll n, m, c[N], ans, a[N], now, tmp;
string s;
bool flag;
void solve()
{
	ans = 0;
	do
	{
		now = tmp = 0;
		for(int i = 1; i <= n; i++)
		{
//			cout << a[i] << " ";
			if(c[a[i]] > tmp && s[i] == '1')
			{
				tmp = 0;
				now++;
			}
			else
			{
				tmp++;
			}
		}
//		cout << endl;
		if(now >= m)
		{
			ans++;
			ans %= mod;
		}
	}
	while(next_permutation(a + 1, a + n + 1));
	cout << ans;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	ans = 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] = i;
		ans = ans * i % mod;
	}
	s = " " + s;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
		{
			flag = 1;
		}
	}
	if(!flag || m == 1)
	{
		cout << ans;
		return 0;
	}
	if(n <= 18)
	{
		solve();
		return 0;
	}
	cout << 0;
	return 0;
}
