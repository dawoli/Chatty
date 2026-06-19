#include <iostream>
#include <cstdio>
using namespace std;
int t;
int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n < 2){
			cout << "-1" << endl;
			continue;
		}else if(n <= 7){
			for(int i = 1; i <= 9; i++){
				if(num[i] == n){
					cout << i << endl;
					break;
				}
			}
			continue;
		}
		
		
		if(n % 7 == 0){
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}else if(n % 7 == 1){
			cout << 10;
			n -= 8;
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}else if(n % 7 == 2){
			cout << 1;
			n -= 2;
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}else if(n % 7 == 3){
			cout << 22;
			n -= 10;
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}else if(n % 7 == 4){
			cout << 20;
			n -= 11;
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}else if(n % 7 == 5){
			cout << 2;
			n -= 5;
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}else if(n % 7 == 6){
			cout << 6;
			n -= 6;
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
		}
	}
	return 0;
}
