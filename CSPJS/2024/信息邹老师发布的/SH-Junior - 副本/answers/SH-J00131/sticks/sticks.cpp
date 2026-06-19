#include<iostream>
using namespace std;

int l[120] = {-1, -1 ,1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888, 8888};

void print(int f){
	for(int i = 0; i < f; i++){
		cout << 8;
	}
	cout << endl;
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int n, t;
	cin >> t;
	for(int i = 0 ; i < t; i++){
		cin >> n;
		if(n < 2){
			cout << -1 << endl;
			continue;
		}
		if(n < 29){
			cout << l[n] << endl;
			continue;
		}
		int a = (n + 6) / 7;
		int k = a * 7 - n;
		switch (k){
			case 0:{
				print(a);
				break;
			}
			case 1:{
				cout << 6;
				print(a - 1);
				break;
			}
			case 2:{
				cout << 2;
				print(a - 1);
				break;
			}
			case 3:{
				cout << 20;
				print(a - 2);
				break;
			}
			case 4:{
				cout << 200;
				print(a - 3);
				break;
			}
			case 5:{
				cout << 1;
				print(a - 1);
				break;
			}
			case 6:{
				cout << 10;
				print(a - 2);
				break;
			}
		}
	}
	
	return 0;
} 
