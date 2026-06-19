#include <bits/stdc++.h>
using namespace std;
int t, s[100005];
int a[100005], ans;
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--) {
		int m, l, v;
		int n; cin >> n >> m >> l >> v;
		int a[1000005] = {0};
		int ans1 = 0;
		for (int i = 1; i <= n; i++) {
			int z, b, c;
			cin >> z >> b >> c;
			if (z > l) {
				a[b]++;
				a[c+1]--;
				ans1++;
			}
		}
		for (int i = 1; i <= l; i++) {
			a[i] = a[i-1] + a[i];
		}
		int p[1000005] = {0};
		for (int i = 1; i <= m; i++) {
			cin >> p[i];
			a[p[i]] ^= 1073741824;
		}
		int ans = 0;
		for (int i = 1; i <= l; i++) {
			if (a[i] > 1073741824) ans++;
		}
		cout << ans1 << " " << ans;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
