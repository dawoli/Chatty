#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum[500005], dp[500005], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int maxj = n;
	for (int i = n; i > 0; i--) {
		for (int j = i; j <= maxj; j++) {
			int tmp = sum[j] ^ sum[i - 1];
			if (tmp == k) {
				ans++;
				maxj = i - 1;
				break; 
			}
		}
	}
	cout << ans <<'\n';
	return 0;
}
/*
500000/128/2
*/
