#include <bits/stdc++.h>
using namespace std;
#define int long long

int lst[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int N = 1e5 + 10;
int n, T;

signed main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n % 7 == 0) {
			for (int i = 1; i <= n / 7; i++) {
				cout << 8;
			}
			cout << endl;
		}
		else if (n % 7 == 1) {
			cout << 10;
			for (int i = 1; i < (n - 1) / 7; i++) {
				cout << 8;
			}
			cout << endl;
		}
		else {
			int tmp = n % 7;
			for (int i = 1; i <= 9; i++) {
				if (lst[i] == tmp) {
					cout << i;
				}
			} 
			for (int i = 1; i < (n - tmp) / 7; i++) {
				cout << 8;
			}
			cout << endl;
		}
	}
	
}
