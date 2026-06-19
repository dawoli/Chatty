#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ans[] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
string prefix[] = {"888", "108", "188", "200", "208", "288", "688"};

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n <= 14) cout << ans[n];
		else {
			cout << prefix[n % 7];
			for (int i = 1; i <= (n + 6) / 7 - 3; i++) {
				cout << 8;
			}
		}
		cout << endl;
	} 
	return 0;
}

