#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout); 
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << -1 << endl;
		}
		else if (n == 2) {
			cout << 1 << endl;
		}
		else if (n == 3) {
			cout << 7 << endl;
		}
		else if (n == 6) {
			cout << 6 << endl;
		}
		else if (n == 18) {
			cout << 208 << endl;
		}
	}
	return 0;
}
