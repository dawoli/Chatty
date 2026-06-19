#include<bits/stdc++.h>
using namespace std;
int num[10] = {-1, -1, 1, 7, 4, 2, 6, 8};
int t;
int n;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		if(n <= 7) {
			cout << num[n] << endl;
			continue;
		}
		if(n % 7 == 0){
			for(int i = 1; i <= n / 7; i++){
				cout << '8';
			}
		}else if(n % 7 == 1){
			cout << 1;
			for(int i = 2; i <= n / 7; i++) cout << 8;
		}
		cout << endl;
	}
	return 0;
}
