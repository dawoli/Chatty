#include<iostream>
using namespace std;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	bool a[5][20] = {0};
	cin >> n;
	char k[3];
	int b, c;
	for(int i = 0; i < n; i++){
		cin >> k[0] >> k[1];
		if(k[0] == 'D'){
			b = 0;
		}else if(k[0] == 'C'){
			b = 1;
		}else if(k[0] == 'H'){
			b = 2;
		}else{
			b = 3;
		}
		if(k[1] == 'A'){
			c = 1;
		}else if(k[1] == 'T'){
			c = 10;
		}else if(k[1] == 'J'){
			c = 11;
		}else if(k[1] == 'Q'){
			c = 12;
		}else if(k[1] == 'K'){
			c = 13;
		}else{
			c = k[1] - '0';
		}
		a[b][c] = 1;
	}
	int ans = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 1; j < 14; j++){
			if(! a[i][j]){
				ans++;
			}
		}
	}
	cout << ans;
	
	return 0;
} 
