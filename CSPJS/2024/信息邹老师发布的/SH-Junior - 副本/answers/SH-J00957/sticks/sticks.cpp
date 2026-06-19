#include <iostream> 

using namespace std;

int T, n;

int main(){
	
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	cin >> T;
	while(T--){
		cin >> n;
		if(n == 1) cout << -1;
		else if(n <= 9){
			if(n == 2) cout << 1;
			else if(n == 3) cout << 7;
			else if(n == 4) cout << 4;
			else if(n == 5) cout << 2;
			else if(n == 6) cout << 6;
			else if(n == 7) cout << 8;
			else if(n == 8) cout << 10;
			else if(n == 9) cout << 18;
		}
		else if(n % 7 == 0){
			for(int i = 1; i <= n/7; i++){
				cout << 8;
			}
		}
		else if(n % 7 == 1){
			cout << 10;
			for(int i = 1; i < n/7; i++){
				cout << 8;
			}
		}
		else if((n-10) % 7 == 0){
			cout << 22;
			for(int i = 1; i < n/7; i++){
				cout << 8;
			}
		}
		else if((n-11) % 7 == 0){
			cout << 20;
			for(int i = 1; i < n/7; i++){
				cout << 8;
			}
		}
		else{ 
			int x = n % 7;
			if(x == 2) cout << 1;
			else if(x == 3) cout << 7;
			else if(x == 4) cout << 4;
			else if(x == 5) cout << 2;
			else if(x == 6) cout << 6;
			for(int i = 1; i <= n/7; i++){
				cout << 8;
			}
		}
		
		cout << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
