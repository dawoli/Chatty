#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int T;
	cin >> T;
	
	for(int i = 1; i <= T; i++) {
		int n;
		cin >> n;
		int Mod = n % 7;
		int Div = n / 7;
		if ((Div == 0) && (Mod == 1)) {
			cout << -1 << "\n";
		} else if (Mod == 0) {
			for (int i = 1; i <= Div; i++) {
				cout << 8;
			} 
			cout << "\n";
		} else if (Mod == 1) {
			cout << 1 << 0;
			for (int i = 1; i <= Div - 1; i++) {
				cout << 8;
			}
			cout << "\n";
		} else if (Mod == 2) {
			cout << 1;
			for (int i = 1; i <= Div; i++) {
				cout << 8;
			}
			cout << "\n";
		} else if (Mod == 3) {
			cout << 7;
			for (int i = 1; i <= Div; i++) {
				cout << 8;
			}
			cout << "\n";
		} else if (Mod == 4) {
			cout << 2 << 0;
			for (int i = 1; i <= Div - 1; i++) {
				cout << 8;
			}
			cout << "\n";
		} else if (Mod == 5) {
			cout << 2;
			for (int i = 1; i <= Div; i++) {
				cout << 8;
			}
			cout << "\n";
		} else if (Mod == 6) {
			cout << 6;
			for (int i = 1; i <= Div; i++) {
				cout << 8;
			}
			cout << "\n";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
} 
