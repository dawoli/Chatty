#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("sticks.in", "w", stdin);
	freopen("sticks.out", "r", stdout);
	cin >> T;
	for (int a = 1; a <= T; a ++){
		cin >> n;
		if (n <= 1) {
			cout << -1;
			break;
		}if (n == 2){
			cout << 1;
			break;
		}if (n == 3){
			cout << 7;
			break;
		}if (n == 4){
			cout << 4;
			break;
		}if (n == 5){
			cout << 2;
			break;
		}if (n == 6){
			cout << 6;
			break;
		}if (n == 7){
			cout << 8;
			break;
		} int p = n % 7;
		if (p == 0) cout << 8;
		if (p == 1) cout << 10;
		if (p == 2) cout << 18;
		if (p == 3) cout << 22;
		if (p == 4) cout << 20;
		if (p == 5) cout << 28;
		if (p == 6) cout << 68;
		for (int i = 1; i <= (n - p)/7 - 1; i ++) cout << 8;
		cout << endl;
	}
	return 0;
}
