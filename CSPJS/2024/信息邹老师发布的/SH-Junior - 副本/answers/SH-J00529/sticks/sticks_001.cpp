#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		if (n <= 1){
			cout << -1 << endl;
			continue;
		}
		if (n <= 20){
			if (n == 2) cout << 1 << endl;
			if (n == 3) cout << 7 << endl;
			if (n == 4) cout << 4 << endl;
			if (n == 5) cout << 2 << endl;
			if (n == 6) cout << 6 << endl;
			if (n == 7) cout << 8 << endl;
			if (n == 8) cout << 10 << endl;
			if (n == 9) cout << 18 << endl;
			if (n == 10) cout << 22 << endl;
			if (n == 11) cout << 20 << endl;
			if (n == 12) cout << 28 << endl;
			if (n == 13) cout << 68 << endl;
			if (n == 14) cout << 88 << endl;
			if (n == 15) cout << 108 << endl;
			if (n == 16) cout << 188 << endl;
			if (n == 17) cout << 228 << endl;
			if (n == 18) cout << 208 << endl;
			if (n == 19) cout << 288 << endl;
			if (n == 20) cout << 688 << endl;
			continue;
		}
		int k = n % 7;
		if (k == 0){
			for (int i = 1; i <= n / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
		if (k == 1){
			cout << 10;
			for (int i = 1; i < (n-1) / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
		if (k == 2){
			cout << 1;
			for (int i = 1; i <= (n-2) / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
		if (k == 3){
			cout << 22;
			for (int i = 1; i < (n-3) / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
		if (k == 4){
			cout << 20;
			for (int i = 1; i < (n-4) / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
		if (k == 5){
			cout << 2;
			for (int i = 1; i <= (n-5) / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
		if (k == 6){
			cout << 6;
			for (int i = 1; i <= (n-2) / 7; i++) cout << 8;
			cout << endl;
			continue;
		}
	}
	return 0;
}
