#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int a[5000];
bool b[5000];
int n, ans;
void f(int x) {
	b[x] = !b[x];
	if (x < n - 1) {
		f(x + 1);
		f(x + 1);
	} else {
		int len = 0, mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (b[i]) {
				len += a[i];
				if (!mx) mx = a[i];
			}
		}
		if (len > mx * 2) ans++;
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	f(0); f(0);
	cout << ans;
	return 0;
}
