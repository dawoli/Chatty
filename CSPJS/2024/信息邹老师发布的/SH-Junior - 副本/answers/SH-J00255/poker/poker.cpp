#include<bits/stdc++.h>

using namespace std;

bool a[10][20]; // a[1~4]分别是黑桃、红桃、草花、方块，a[x][1~13]表示A到K 

int cnt(char y){
	if('2' <= y && y <= '9') return y-'0';
	else if(y == 'A') return 1;
	else if(y == 'T') return 10;
	else if(y == 'J') return 11;
	else if(y == 'Q') return 12;
	else if(y == 'K') return 13;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i ++){
		char x,y; cin >> x >> y;  // x是花色，y是点数
		
		if(x == 'S') a[1][cnt(y)] = 1;
		else if(x == 'H') a[2][cnt(y)] = 1;
		else if(x == 'C') a[3][cnt(y)] = 1;
		else if(x == 'D') a[4][cnt(y)] = 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= 4; i ++) for(int j = 1; j <= 13; j ++){
		ans += !a[i][j];
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
