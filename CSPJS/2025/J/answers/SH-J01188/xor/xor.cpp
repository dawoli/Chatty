#include <bits/stdc++.h>
using namespace std;
int n, k, a[1001], sum[1001][1001], ans; 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	// 前缀和
	cin >> n >> k;
	// 贪心先拿上那60分 
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		sum[i] = (sum[i - 1] xor a[i]);
		sum[1][i] = (sum[1][i - 1] xor a[i]);
		for (int j = 2; j <= i; j++) sum[j][i] = (sum[1][i] xor sum[1][j - 1]);
	} 
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			bool check = false;
			for (int k = l; k <= r; k++) {
				if (sum[k][r] == k) {
					check = true;
					ans++;
//					cout << k << " k " << r << "\n";
					l = r;
					break;
				}
			}
			if (check) break; 
			if (sum[l][r] == k) {
				ans++;
//				cout << l << " " << r << "\n";
				l = r;
				break;
			}
		}
	} 
	cout << ans << endl;
	return 0;
}
