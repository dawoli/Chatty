#include<bits/stdc++.h>
using namespace std;
int n, cnt, t, k[110], ans;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		char a, b;
		cin >> a >> b;
		cnt = 0, t = 0;
		if(a == 'D') cnt = 0;
		if(a == 'C') cnt = 13;
		if(a == 'H') cnt = 26;
		if(a == 'S') cnt = 39;
		if(b == 'A') t = 1;
		if(b == 'T') t = 10;
		if(b == 'J') t = 11;
		if(b == 'Q') t = 12;
		else if(b == 'K') t = 13;
		else t = b - '0';
		k[cnt + t]++;
	}
	for(int i = 1;i <= 52;i++){
		if(k[i] == 0)ans++;
	}
	cout << ans;
	return 0;
} 
