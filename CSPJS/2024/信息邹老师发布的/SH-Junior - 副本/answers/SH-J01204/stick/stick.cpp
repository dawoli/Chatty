#include <bits/stdc++.h>
using namespace std;
int db[21] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 608, 808};
int T, n;
int main(){
	freopen("stick.in", "r", stdin);
	freopen("stick.out", "w", stdout);
	cin >> T;
	for(int i = 1; i <= T; i ++){
		cin >> n;
		if(n == 1) cout << -1;
		else if(n <= 20) cout << db[n];
		else if(n % 7 == 0){
			for(int i = 1; i <= n / 7; i ++) cout << 8;
		}
		else if(n % 7 == 1){
			cout << 10;
			for(int i = 1; i <= (n - 8) / 7; i ++) cout << 8;
		}
		else if(n % 7 == 2){
			cout << 1;
			for(int i = 1; i <= (n - 2) / 7; i ++) cout << 8;
		}
		else if(n % 7 == 6){
			cout << 80;
			for(int i = 1; i <= (n - 13) / 7; i ++) cout << 8;
		}
		cout << endl;
	}
	return 0;
}
// 6, 2, 5, 5, 4, 5, 6, 3, 7, 6
