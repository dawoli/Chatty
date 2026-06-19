#include <bits/stdc++.h>
using namespace std;
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int digit_number = (n + 6) / 7;
		if (digit_number <= 2){
			if (n == 1) cout << "-1\n";
			if (n == 2) cout << "1\n";
			if (n == 3) cout << "7\n";
			if (n == 4) cout << "4\n";
			if (n == 5) cout << "2\n";
			if (n == 6) cout << "6\n";
			if (n == 7) cout << "8\n";
			if (n == 8) cout << "10\n";
			if (n == 9) cout << "18\n";
			if (n == 10) cout << "22\n";
			if (n == 11) cout << "20\n";
			if (n == 12) cout << "28\n";
			if (n == 13) cout << "68\n";
			if (n == 14) cout << "88\n";
			continue;
		}
		if (n % 7 == 1){
			cout << "108";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}
		if (n % 7 == 2){
			cout << "188";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}
		if (n % 7 == 3){
			cout << "200";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}
		if (n % 7 == 4){
			cout << "208";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}
		if (n % 7 == 5){
			cout << "288";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}
		if (n % 7 == 6){
			cout << "688";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}
		if (n % 7 == 0){
			cout << "888";
			for (int i = 1; i <= digit_number - 3; i++){
				cout << "8";
			}
			cout << endl;
		}	
		 
	}
}  
