#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n, a[N], mp[N], ct, mx;
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);	
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], mx = max(mx, a[i]), ++mp[a[i]];
	for (int i = 1, nw = 0; i <= mx; ++i) {
		if (!mp[i]) continue;
		int t = min(nw, mp[i]);
		ct += t, nw = nw - t + mp[i];
	}
	cout << n - ct << endl;
} 
