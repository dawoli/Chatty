#include <bits/stdc++.h>
using namespace std;

long long n, k, ans, s = 1;
long long a[500005];

long long xr(int l, int r) {
    long long cnt = a[l];
	for (int i = l + 1; i <= r; i++) {
		cnt ^= a[i];
	} 
	return cnt;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = s; j <= i; j++) {
			if (xr(j, i) == k) {
				cout << j << " " << i << endl;
				ans++;
				s = i + 1;
				break;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

