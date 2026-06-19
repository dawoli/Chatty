#include <bits/stdc++.h>
using namespace std;
int stick[21] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 180, 188, 200, 208,288, 808};
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if(n <= 20){
			cout << stick[n];
			continue;
		}
		if(n % 7 == 0) {
			for(int i = 1; i <= n/7; i++) {
				cout << 8;
			}
			continue;
		}
		else if(n % 7 == 1) {
			cout << 10;
			for(int i = 1; i < n/7; i++) {
				cout << 8;
			}
			continue;
		}
	}
	return 0;
}
