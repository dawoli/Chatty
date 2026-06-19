#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 7;
string s1[N], s2[N], t1, t2;
int n, q;
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	while(q--)
	{
		int ans = 0, mx = 0, mn = 1e9;
		cin >> t1 >> t2;
		for(int i = 0; i < t1.size(); i++)
			if(t1[i] != t2[i])
				mx = i, mn = (mn != 1e9 ? mn : i);
		for(int i = 1; i <= n; i++)
		{
			if(s1[i].size() < mx - mn + 1 || s1[i].size() > t1.size())
				continue;
			for(int j = max(0LL, mx - (signed)s1[i].size() + 1); j + s1[i].size() <= t1.size() && j <= mn + s1[i].size() - 1; j++)
				if(s1[i] == t1.substr(j, s1[i].size()) && s2[i] == t2.substr(j, s1[i].size()))
					ans++;
		}
		cout << ans << endl; 
	} 
	return 0;
}
// ÉÙÓðÅ£±Æ 
