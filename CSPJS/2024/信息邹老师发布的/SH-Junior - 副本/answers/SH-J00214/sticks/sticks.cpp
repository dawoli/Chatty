#include<bits/stdc++.h>
using namespace std;

int t; 

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		if(n == 1){
			cout << -1 << endl;
		}
		else{
			if(n % 7 == 1){//10888888888888888888888 
				n -= 8;
				
				cout << 10;
				
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
			else if(n % 7 == 2){//188888888888888888888888
				n -= 2;
				
				cout << 1;
				
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
			else if(n % 7 == 3){//7888888888888888888888888888
				n -= 10;
				
				cout << 22;
				
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
			else if(n % 7 == 4){//4888888888888888888888888888
				n -= 11;
				
				cout << 20;
				
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
			else if(n % 7 == 5){//288888888888888888888888
				n -= 5;
				
				cout << 2;
				
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
			else if(n % 7 == 6){//688888888888888888888888888888
				n -= 6;
				
				cout << 6;
				
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
			else{//888888888888888888888888888888888888888888888888888
				for(int i = 1;i <= n / 7;i++) cout << 8;
				
				cout << endl;
			}
		}
	}
	return 0;
}
