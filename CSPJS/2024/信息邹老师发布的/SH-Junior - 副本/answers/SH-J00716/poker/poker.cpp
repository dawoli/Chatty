#include<bits/stdc++.h>
using namespace std;
int n,x,y,ans;
bool card[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 0; i <n ; i++){
		char a,b;
		cin >> a >> b;
		if(a == 'S'){
			x = 0;
		}
		else if(a == 'H'){
			x = 1;
		}
		else if(a == 'C'){
			x = 2;
		}
		else if(a == 'D'){
			x = 3;
		}
		if('2' <= b && b <= '9'){
			y = b-'0'-1;
		}
		else if(b == 'A'){
			y = 0;
		}
		else if(b == 'T'){
			y = 9;
		}
		else if(b == 'J'){
			y = 10;
		}
		else if(b == 'Q'){
			y = 11;
		}
		else if(b == 'K'){
			y = 12;
		}
		card[x][y] = true;
	}
	for(int i = 0; i <4; i++){
		for(int j = 0; j <13; j++){
			if(!card[i][j]){
				ans++;
			}
		}
	} 
	cout << ans;
	return 0;
}
