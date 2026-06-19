#include<bits/stdc++.h>
using namespace std;
int T, cnt = 1, t, ans;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		int n;
		cin >> n;
		if(n == 1)cout << -1 << endl;
		if(n == 3)cout << 7 << endl;
		if(n == 4)cout << 4 << endl;
		if(n == 5)cout << 2 << endl;
		if(n == 6)cout << 6 << endl;
		if(n == 10)cout << 22 << endl;
		if(n == 11)cout << 20 << endl;
		if(n == 12)cout << 28 << endl;
		if(n == 13)cout << 68 << endl;
		if(n == 17)cout << 200 << endl;
		if(n == 18)cout << 208 << endl;
		if(n == 19)cout << 288 << endl;
		if(n == 20)cout << 808 << endl;
		if(n % 7 == 0){
			int t = n / 7;
			while(t){
				cout << 8;
				t--;
			}
			cout << endl;
		}
		if(n % 7 == 1 && n >= 8){
			cout << 10;
			int t = n / 7 - 1;
			while(t){
				cout << 8;
				t--;
			}
			cout << endl;
		}
		if(n % 7 == 2){
			cout << 1;
			int t = n / 7;
			while(t){
				cout << 8;
				t--;
			}
			cout << endl;
		}
		if(n % 7 == 3 && n >= 24){
			cout << 200;
			int t = n / 7 - 2;
			while(t){
				cout << 8;
				t--;
			}
		}
		if(n % 7 == 4 && n >= 25){
			cout << 20;
			int t = n / 7 - 1;
			while(t){
				cout << 8;
				t--;
			}
		}
		if(n % 7 == 5 && n >= 26){
			cout << 2;
			int t = n / 7;
			while(t){
				cout << 8;
				t--;
			}
		}
		if(n % 7 == 6 && n >= 27){
			cout << 6;
			int t = n / 7;
			while(t){
				cout << 8;
				t--;
			}
		}
	}
	return 0;
}
