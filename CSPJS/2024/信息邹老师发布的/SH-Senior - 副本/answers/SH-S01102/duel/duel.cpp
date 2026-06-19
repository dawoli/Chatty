#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
int n;
int a[N], s[N];
int maxa = -1, pos = 0;
int ans = 0;

int main () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = a[i];
		maxa = max(a[i], maxa);
	}
	if (maxa <= 2) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 1) {
				cnt1 ++;
			}
			else if (a[i] == 2) {
				cnt2 ++;
			}
		}
		if (cnt2 >= cnt1) {
			ans = n - cnt1;
		}
		else if (cnt2 < cnt1) {
			ans = n - cnt2;
		}
		cout << ans;
		return 0;
	}
	sort (a + 1, a + n + 1);
	sort (s + 1, s + n + 1);
	pos = upper_bound(a + 1, a + n + 1, a[1]) - a;
	// a[1] attack must fail
	// out: -1, done: 0
	a[1] = -1;
	a[pos] = 0; 
	for (int i = 2; i <= n; i ++) {
//		auto *it = upper_bound(a + i, a + n + 1, a[i]);
//		if (*it != 0) {
//			ans ++;
//		}
//		a[it - a] = -1;
		while (pos == i || a[pos] == 0 || s[pos] <= s[i]) {
			pos ++;
//		cout << "[" << pos << "]";
			if (pos > n) {
				pos = 0;
				break;
			}
		}
		if (pos == 0) {
			break;
		}
//		cout << pos << ":" << a[pos] << " BEAT " << i << ":" << a[i] << endl;
		a[i] = -1;
		a[pos] = 0;
	}
	for (int i = 1; i <= n; i ++) {
//		cout << a[i] << " ";
		if (a[i] != -1) {
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
