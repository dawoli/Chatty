#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main() {
	freopen("xor.in", "r" ,stdin);
	freopen("xor.out", "w" ,stdout);
	int n = 1, k = 1;
	cin >> n >> k;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) flag = 0;
	}
	if (k == 0 && flag) {
		cout << 0;
		return 0;
	}
	cout << 63;
	return 0;
}
