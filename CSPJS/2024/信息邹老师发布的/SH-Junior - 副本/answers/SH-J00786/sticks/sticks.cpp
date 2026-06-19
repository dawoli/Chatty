#include <bits/stdc++.h>
using namespace std;

int a[21] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int n, t;
	cin >> t;
	a[1] = -1;
	while (t--) {
		cin >> n;
		if (n % 7 == 0) {
			for (int i = 1; i <= n/7; i++) {
				cout << 8;
			} 
			cout << "\n";
			continue;
		}
		if (n % 7 == 1 && n > 1) {
			cout << 10;
			for (int i = 1; i < n/7; i++) {
				cout << 8;
			}
			cout << "\n";
			continue;
		}
		if (n <= 20) {
			if (n == 1) {
				cout << -1 << "\n"; continue;
			}
			cout << a[n] << "\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
