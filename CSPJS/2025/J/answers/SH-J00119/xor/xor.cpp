#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int a[maxn], x[maxn];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	x[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x[i] = x[i-1] ^ a[i];
	}
	int pr = 0, ans = 0;
	for (int r = 1; r <= n; r++) {
		for (int l = r; l > pr; l--) {
			if ((x[r] ^ x[l - 1]) == k) {
				ans++;
				pr = r;
			}
		}
	}
	cout << ans;
	return 0;
}
