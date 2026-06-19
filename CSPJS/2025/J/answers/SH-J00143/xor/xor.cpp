#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, a[200005], ans = 0;
	bool b[200005];
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i <= n;i++) b[i] = true;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < n - i + 1;j++) {
			if (i == 1) {
				if (!b[j]) continue;
				if (a[j] == k) {
					ans++;
					b[j] = false;
				}
				continue;
			}
			bool flag = true;
			int x = a[j];
			for (int p = j;p < j + i;p++) {
				if(!b[p]) {
					flag = false;
				}
				if (p == j) continue;
				x = x ^ a[p];
			}
			if (flag) {
				if (x == k) {
					ans++;
					for (int p = j;p < j + i;p++) {
						b[p] = false;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
