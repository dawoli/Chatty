#include <bits/stdc++.h>
using namespace std;

unsigned long long a[500005];
int b[500005];
int main() {
	//10+
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	bool flag = true;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			flag = false;
		}
	}
	if (k == 0 && flag) {
		cout << n / 2 << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			//cout << (a[i] ^ k) << " ";
			a[i] ^= k;
		}
		//cout << endl;
		int sum = 0;
		for (int i = 1; i <= n-1; i++) {
			b[i] = a[i] - a[i+1];
			if (a[i] == 0) {
				sum ++;
				b[i] = 0x7fffffff;
			}
			//cout << b[i] << " ";
		}
		//cout << endl;
		if (a[n] == 0) sum ++;
		int d = b[1], cnt = 0;
		for (int i = 1; i <= n-1; i++) {
			if (b[i] != d) {
				if (cnt > 2) sum ++;
				d = b[i];
			}
			else {
				cnt ++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
