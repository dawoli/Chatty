#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], ans;
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	int cnt = 0, mem = 1;
	for (int i=2; i<=n; i++) {
		if (a[i] == a[i-1]) mem ++;
		else if (a[i] > a[i-1]) {
			cnt += mem;
			mem = 1;
		}
		if (cnt > 0) {
			cnt --;
			ans ++;
		}
	}
	cout << (n - ans);
	return 0;
}
