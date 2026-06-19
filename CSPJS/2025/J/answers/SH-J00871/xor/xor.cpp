#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], s[500010], f[500010][2];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		s[i] = 1e9;
		int sum = 0;
		for(int j = i; j >= 1; j--) {
			sum ^= a[j];
			if(sum == k) {s[i] = i - j + 1; break;}
		}
	}
	//for(int i = 1; i <= n; i++) cout << s[i] << "\n";
	//cout << "\n";
	for(int i = 1; i <= n; i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		if(i >= s[i]) f[i][1] = max(f[i - s[i]][0], f[i - s[i]][1]) + 1;
		else f[i][1] = -1e9;
	}
	cout << max(f[n][0], f[n][1]) << "\n";
	return 0;
}
