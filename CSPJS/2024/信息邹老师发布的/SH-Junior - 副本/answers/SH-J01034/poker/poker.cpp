#include <bits/stdc++.h>
using namespace std;
int n, ans, a[15][5];
string s;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	while(n--){
		cin>>s;
		int hs, ds;
		if(s[0] == 'D') hs = 1; 
		else if(s[0] == 'C') hs = 2; 
		else if(s[0] == 'H') hs = 3; 
		else hs = 4; 
		
		if(s[1] >= '2' && s[1] <= '9') ds = s[1]-'0';
		else if(s[1] == 'A') ds = 1;
		else if(s[1] == 'T') ds = 10;
		else if(s[1] == 'J') ds = 11;
		else if(s[1] == 'Q') ds = 12;
		else if(s[1] == 'K') ds = 13;
		a[ds][hs] = 1;
	}
	for(int i = 1;i <= 13;i++) 
		for(int j = 1;j <= 4;j++)
			ans += a[i][j];
	cout<<52-ans;
	return 0;
}
