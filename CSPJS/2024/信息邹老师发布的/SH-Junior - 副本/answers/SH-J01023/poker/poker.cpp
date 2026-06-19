#include<iostream>
using namespace std;
char p1, p2;
int poker[5][15];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	int n, ans = 0;
	cin >> n;
	while(n--){
		cin >> p1 >> p2;
		int x, y;
		if(p1 == 'D'){
			x = 1;
		}else if(p1 == 'C'){
			x = 2;
		}else if(p1 == 'H'){
			x = 3;
		}else{
			x = 4;
		}
		if(p2 >= '2' && p2 <= '9'){
			y = (p2-'0');
		}else if(p2 == 'A'){
			y = 1;
		}else if(p2 == 'T'){
			y = 10;
		}else if(p2 == 'J'){
			y = 11;
		}else if(p2 == 'Q'){
			y = 12;
		}else{
			y = 13;
		}
		poker[x][y] = 1;
	}
	for(int i=1; i<=4; i++){
		for(int j=1; j<=13; j++){
			if(!poker[i][j]){
				ans++;
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
