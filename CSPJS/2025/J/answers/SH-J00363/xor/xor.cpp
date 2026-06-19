#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int a[N];

int yhh(int l, int r) {
	if (l == r) {
		return a[l];
	}
	int ret = a[l];
	for (int i = l+1; i <= r; i++) {
		ret ^= a[i];
	}
	return ret;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0 && a[i] != 1) {
			flag = 1;
		}
	}
	int cnt = 0;
	if (flag == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				cnt++;
			}
		}
		cout << cnt;
		return 0; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (yhh(a[i], a[j]) == k) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
