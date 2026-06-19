#include <iostream>
using namespace std;
int ans[14] = {-1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int T, n; 
void solve() {
	cin >> n;
	if (n <= 14) cout << ans[n - 1] << endl;
	else {
		int n2 = n % 7;
		if (n2 == 1) {
			cout << "10";
			n -= 8;
		}
		if (n2 == 2) {
			cout << "1";
			n -= 2;
		}
		if (n2 == 3) {
			cout << "200";
			n -= 17;
		}
		if (n2 == 4) {
			cout << "20";
			n -= 11;
		}
		if (n2 == 5) {
			cout << "2";
			n -= 5;
		}
		if (n2 == 6) {
			cout << "6";
			n -= 6;
		}
		for (int i = 1; i <= n / 7; i++) cout << 8;
		cout << endl; 
	}
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout); 
	cin >> T;
	while (T--) solve();
	return 0;
}

