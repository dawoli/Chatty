#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t, x;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> x;
		if(x % 7 == 0) {
			for(int j = 1; j <= x/7; j++) {
				cout << 8;
			}
			cout << endl;
		}else if(x % 7 == 1){
			cout << 1 << 0;
			for(int j = 1; j <= (x-8)/7; j++) {
				cout << 8;
			}
			cout << endl;
		}else{
			cout << -1 << endl;
		}
	}
	return 0;
} 
