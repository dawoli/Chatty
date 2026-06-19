#include <bits/stdc++.h>
using namespace std;
void f(int x){
	if(x == 0){
		return;
	}
	if(x == 2){
		cout << 1;
		return;
	}
	if(x == 3){
		cout << 7;
		return;
	}
	if(x == 4){
		cout << 4;
		return;
	}
	if(x == 5){
		cout << 2;
		return;
	}
	if(x == 6){
		cout << 0;
		return;
	}
	if(x % 7 == 0){
		for(int j = 0 ; j < x / 7 ; j++){
			cout << 8;
		}
		return;
	}
	cout << 0;
	f(x - 6);
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		if(x == 1){
			cout << -1 << endl;
			continue;
		}
		if(x == 2){
			cout << 1 << endl;
			continue;
		}
		if(x == 3){
			cout << 7 << endl;
			continue;
		}
		if(x == 4){
			cout << 4 << endl;
			continue;
		}
		if(x == 5){
			cout << 5 << endl;
			continue;
		}
		if(x == 6){
			cout << 6 << endl;
			continue;
		}
		if(x == 7){
			cout << 8 << endl;
			continue;
		}
		if(x % 7 == 0){
			for(int j = 0 ; j < x / 7 ; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(x % 7 == 1){
			cout << 10;
			for(int j = 0 ; j < x / 7 - 1 ; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(x % 7 == 2){
			cout << 1;
			for(int i = 0 ; i < x / 7 ; i++){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		cout << 2;
		f(x - 5);
		cout << endl;
	}
} 
