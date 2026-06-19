#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool f[10][50];
int main () {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> s;
		int x, y; //»¨É«£¬Êý×Ö
		if(s[0] == 'D') x = 1;
		else if(s[0] == 'C') x = 2;
		else if(s[0] == 'H') x = 3;
		else if(s[0] == 'S') x = 4;
		if(s[1] >= '2' && s[1] <= '9') y = s[1]-'0';
		else if(s[1] == 'A') y = 1;
		else if(s[1] == 'T') y = 10;
		else if(s[1] == 'J') y = 11;
		else if(s[1] == 'Q') y = 12;
		else if(s[1] == 'K') y = 13;
		//cout << x << ' ' << y << endl;
		if(f[x][y] == false) {
			ans ++;
			f[x][y] = true;
		}
	}
	
	cout << 52-ans;
	
	return 0;
} 
