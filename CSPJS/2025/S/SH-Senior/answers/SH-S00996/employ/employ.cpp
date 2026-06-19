#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[100005], flag, perm[100005], pwp[100005];
char c[100005];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
		if(c[i] == 0) flag = 1;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if(m == n) {
		if(flag) {
			cout << 0 << endl;
		}
		else {
			int ans = 1;
			for(int i = 1; i <= n; ++i) ans = ans * i % 998244353;
			cout << ans << endl;
		}
		return 0;
	}
	if(n <= 10) { 
		for(int i = 1; i <= n; ++i) perm[i] = i;
		int T = 1, ans = 0;
		for(int i = 1; i <= n; ++i) T *= i;
		for(int i = 1; i <= T; ++i) {
			int qwq = 0, twt = 0;
			for(int j = 1; j <= n; ++j) {
				if(c[i] == '1') {
					if(qwq <= a[perm[i]]) ++twt;
				}
				else {
					++qwq;
				}
			}
			if(twt >= m) ++ans;
			next_permutation(perm + 1, perm + n + 1);
		}
		cout << ans << endl;
		return 0;
	}
	int ans = 1;
	for(int i = 0; i <= n; ++i) for(int j = 0; j <= a[i]; ++j) ++pwp[j];
	for(int i = 1, qwq = 0, twt = 0; i <= n; ++i) {
		if(c[i] == '1') {
			ans = ans * (pwp[twt] - qwq) % 998244353;
			++qwq;
		}
		else {
			++twt;
		}
	}
	cout << ans << endl;
	return 0;
}
