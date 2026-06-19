#include<bits/stdc++.h>
using namespace std;

int T, n;	 //    2  3  4  5  6  		  7
int a[10] = {0, 0, 1, 7, 4, 2, 6,/* (0) */8};					

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		if(n == 1) cout << -1 << endl;
		else if(n == 2) cout << 1 << endl;
		else if(n == 3) cout << 7 << endl;
		else if(n == 4) cout << 4 << endl;
		else if(n == 5) cout << 2 << endl;
		else if(n == 6) cout << 6 << endl; 
		else if(n % 7 == 0){
			int cnt = n / 7;
			while(cnt){
				cout << 8;
				cnt--;
			}
			cout << endl;
		}
		else if(n % 7 == 1){
			cout << 10;
			int cnt = (n - 1) / 7 - 1;
			while(cnt){
				cout << 8;
				cnt--;
			}
			cout << endl;
		}
	} 
	return 0;
} 
