#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, q;
string s1, s2, t1, t2;
map <ll, vector <pair <string, string> > > mp;
vector <string> v1, v2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (ll i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
		ll l = s1.size(), r = 0;
		for (ll i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])
			{
				l = min(l, i);
				r = max(r, i);
			}
		}
		ll len = r - l + 1;
		mp[len].push_back({s1, s2});
	}
	for (ll i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		ll l = t1.size(), r = 0, ans = 0;
		for (ll i = 0; i < t1.size(); i++)
		{
			if (t1[i] != t2[i])
			{
				l = min(l, i);
				r = max(r, i);
			}
		}
		ll len = r - l + 1;
		for (pair <string, string> i : mp[len])
		{
			ll pp = i.first.size();
			if (pp > t1.size()) continue;
			for (ll j = 0; j + pp - 1 < t1.size(); j++)
			{
				string tmp1 = t1.substr(j, pp);
				string tmp2 = t2.substr(j, pp);
				if (tmp1 == i.first && tmp2 == i.second)
				{
					ans++;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}
