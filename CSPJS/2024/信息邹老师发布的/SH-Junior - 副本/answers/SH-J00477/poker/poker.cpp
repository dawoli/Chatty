#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<string, ll> mp;
void solve()
{
	ll n, ret = 0; cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		string s; cin >> s;
		if (!mp[s]) mp[s] = 1, ret++;
	} cout << 52 - ret << '\n';
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ll T = 1;
	while (T--) solve();
	return 0;
}
