#include <bits/stdc++.h>
using namespace std;
int k;
int a[5][14] = {0}; 
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> k;
	while(k--){
		cin >> s;
		char c_1 = s[0];
		char c_2 = s[1];
		int r_1 = 0;
		int r_2 = 0;
		if('0' <= c_2 && c_2 <= '9'){
			r_2 = int(c_2) - 48;
		}else if(c_2 == 'T'){
			r_2 = 10;
		}else{
			if(c_2 == 'A'){
				r_2 = 1;
			}else if(c_2 == 'J'){
				r_2 = 11;
			}else if(c_2== 'Q'){
				r_2 = 12;
			}else if(c_2 == 'K'){
				r_2 = 13;
			}
		}
		
		if(c_1 == 'D'){
			r_1 = 1;
		}else if(c_1 == 'C'){
			r_1 = 2;
		}else if(c_1 == 'H'){
			r_1 = 3;
		}else if(c_1 == 'S'){
			r_1 = 4;
		}
		a[r_1][r_2] = 1;
	}
	
	int cnt = 52;
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 13; j++){
			if(a[i][j] == 1){
				cnt--;
			}
		}
	}
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
