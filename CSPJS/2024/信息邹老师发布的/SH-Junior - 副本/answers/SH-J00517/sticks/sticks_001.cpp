#include <iostream>
using namespace std;

int list[10] = {-1, -1, 1, 7, 4, 2, 6, 15, 13, 18};

int main(){
	
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int n, t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> n;
		if (n < 10 && n >= 0){
			cout << list[n];
		} else if (n % 7 == 0){
			for (int i = 1; i <= n/7; i++){
				cout << 8;
			}
		} else if (n % 7 == 1){
			cout << 16;
			for (int i = 1; i <= n/7-1; i++){
				cout << 8;
			}
		} else if (n == 18){
			cout << 208;
		} else {
			cout << -1;
		}
		cout << endl;
	}
	
	return 0;
}
