#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, l, r, ans;
string s1[1005], s2[1005], t1, t2;
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while (m--)
	{
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {cout << 0 << endl; continue;}
		k = t1.size(), ans = 0;
		for (int i = 0; i < k; i++) if (t1[i] != t2[i]) {l = i; break;}
		for (int i = k - 1; i >= 0; i--) if (t1[i] != t2[i]) {r = i; break;}
		for (int i = 1; i <= n; i++) for (int j = 0; j + s1[i].size() <= k; j++) if (j <= l && j + s1[i].size() - 1 >= r)
			if (s1[i] == t1.substr(j, s1[i].size()) && s2[i] == t2.substr(j, s2[i].size())) ans++;
		cout << ans << endl;
	}
	return 0;
}
