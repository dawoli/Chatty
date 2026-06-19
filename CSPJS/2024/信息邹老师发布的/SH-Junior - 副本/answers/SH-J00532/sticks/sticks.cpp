#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int single = n % 7, num_of_8 = n / 7;
		if (single == 1){
			if (num_of_8 == 0) cout << -1;
			else{
				cout << 10;
				for (int i = 1; i < num_of_8; i++) cout << 8;
			}
		} else{
			if (single == 2) cout << 1;
			else if (single == 3){
				if (num_of_8 != 0){
					cout << 22;
					num_of_8 -= 1;
				} else cout << 7;
			} else if (single == 4){
				if (num_of_8 != 0){
					cout << 20;
					num_of_8 -= 1;
				} else cout << 4;
			} else if (single == 5) cout << 2;
			else if (single == 6) cout << 6;
			for (int i = 1; i <= num_of_8; i++) cout << 8;
		} cout << endl;
	} return 0;
}
