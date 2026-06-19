#include <iostream>
#include <algorithm>
#define rep(i, l, r) for (int i = l; i <= r; i++)
using namespace std;
int a[1000010], n, ans;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	rep (i, 1, n) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	int l = 1, r = 1;
	ans = n;
	while (l <= n) {
		while (r <= n && a[r] <= a[l]) r++;
		if (r <= n && a[r] > a[l]) {
			ans--;
			r++;
		}
		l++;
	}
	cout << ans << "\n";
}
