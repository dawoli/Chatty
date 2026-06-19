#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, maxx, ans, pre, cnt[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		maxx = max(maxx, a);
		cnt[a]++;
	}
	for (int i = 1; i <= maxx; i++) {
		if (!cnt[i]) continue;
		cout << i << " " << cnt[i] << " ";
		if (!pre) {
			pre = i;
			continue;
		}
		ans += min(cnt[pre], cnt[i]);
		cout << pre << " " << ans << endl;
		pre = i;
	}
	cout << n - ans << endl;
	return 0;
} 
