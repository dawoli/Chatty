#include<bits/stdc++.h>
using namespace std;
int n;
int p[4][20];
string s;
int ans = 0;
int tran1(char x){
	if(x == 'D') return 1;
	else if(x == 'C') return 2;
	else if(x == 'H') return 3;
	else if(x == 'S') return 4;
}
int tran2(char x){
	if(x >= '0' && x <= '9') return x - '0';
	else if(x == 'A') return 1;
	else if(x == 'T') return 10;
	else if(x == 'J') return 11;
	else if(x == 'Q') return 12;
	else if(x == 'K') return 13;
}
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		p[tran1(s[0])][tran2(s[1])] = 1;
	}
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 13; j++){
			if(!p[i][j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
