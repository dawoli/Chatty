#include <bits/stdc++.h>
using namespace std;
#define int long long
#define C 100020
int n, m = 1, ans, maxr, r[C], cnt[C], can[C];
signed main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> r[i];
	sort(r + 1, r + n + 1);
	for(int i = 1; i <= n; i++) {
		cnt[m]++;
		can[m]++;
		if(r[i] != r[i + 1] && i != n)
			m++;
	}
	for(int i = 1; i <= m; i++) {
		int l = i + 1;
		while(l <= m && cnt[i] > can[l]) {
			ans += can[l];
			cnt[i] -= can[l];
			can[l] = 0;
			l++;
		}
		if(can[l] >= cnt[i]) {
			ans += cnt[i];
			can[l] -= cnt[i];
			cnt[i] = 0;
		}
		// for(int i = 1; i <= m; i++)
		// 	cout << cnt[i] << " \n"[i == m];
		// for(int i = 1; i <= m; i++)
		// 	cout << can[i] << " \n"[i == m];
		// cout << ":::" << endl;
	}
	cout << n - ans << endl;
	return 0;
}