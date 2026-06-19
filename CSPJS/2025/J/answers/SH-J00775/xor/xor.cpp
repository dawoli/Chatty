#include<iostream>
using namespace std;

int n, k, a[500010], b[500010], ans, l = 1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int r = 1; r <= n; r++) {
		bool flag = false;
		for (int i = l; i <= r; i++) {
			b[i] = a[r] ^ b[i];
			if (b[i] == k) {
				flag = true;
			}
		}
		if (flag) {
			l = r + 1;
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}  
