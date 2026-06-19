#include <bits/stdc++.h>
using namespace std;

int a[500010] = {};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int ANS = -1, l1 = 1, l = 1, r = 1;
	while (l1 <= n) {
		int ans = 0;
		l = l1;
		r = l1;
		while (r <= n) {
			bool flag = false;
			int t = a[l];
			if (t == k) {
				ans ++;
				l = r + 1;
				r = l;
				continue;
			}
			for (int i = l; i < r; i ++) {
				t = (t ^ (a[i + 1]));
				if (t == k) {
					ans ++;
					l = r + 1;
					r = l;
					flag = true;
					break;
				}
			}
			if (flag) {
				continue;
			}
			r ++;
		}
		ANS = max(ANS, ans);
		l1 ++;
	}
	cout << ANS;
	return 0;
}
