#include <bits/stdc++.h>
using namespace std;
int num[20] = {0, 0, 1, 7, 4, 2, 6, 8, 16, 18, 22, 20, 28, 68};
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n; cin >> n;
		if(n < 2) cout << -1 << "\n";
		else if(n < 14) cout << num[n] << "\n";
		else {
			int x = n / 7, y = n % 7;
			x--; y += 7;
			if(y == 10) cout << 206, x--;
			else cout << num[y];
			for(int i = 1; i <= x; i++) cout << 8;
			cout << "\n";
		}
	}
	return 0;
}
