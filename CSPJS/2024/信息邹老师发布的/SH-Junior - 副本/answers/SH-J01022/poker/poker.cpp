#include<bits/stdc++.h>
using namespace std;


bool ok[6][20];
int n;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		string s;
		cin >> s;
		int k1 = 0, k2 = 0;
		
		if(s[0] == 'D') k1 = 1;
		else if(s[0] == 'C') k1 = 2;
		else if(s[0] == 'H') k1 = 3;
		else if(s[0] == 'S') k1 = 4;
		
		if(s[1] == 'A') k2 = 1;
		else if(s[1] == '2') k2 = 2;
		else if(s[1] == '3') k2 = 3;
		else if(s[1] == '4') k2 = 4;
		else if(s[1] == '5') k2 = 5;
		else if(s[1] == '6') k2 = 6;
		else if(s[1] == '7') k2 = 7;
		else if(s[1] == '8') k2 = 8;
		else if(s[1] == '9') k2 = 9;
		else if(s[1] == 'T') k2 = 10;
		else if(s[1] == 'J') k2 = 11;
		else if(s[1] == 'Q') k2 = 12;
		else if(s[1] == 'K') k2 = 13;
		
		ok[k1][k2] = true;
	}
	int cnt = 0;
	for(int i=1; i<=4; i++) for(int j=1; j<=13; j++) cnt += ok[i][j];
	cout << 52 - cnt;
	return 0;
}

/*
1
SA

51
*/

/*
4
DQ
H3
DQ
DT

49
*/

