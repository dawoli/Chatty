#include<bits/stdc++.h>
using namespace std;
int n, yz[5][15] = {0};
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		char hua, shu;
		cin >> hua >> shu;
		int pd;
		if(hua == 'D') {
			pd = 1;
		}
		if(hua == 'C') {
			pd = 2;
		}
		if(hua == 'H') {
			pd = 3;
		}
		if(hua == 'S') {
			pd = 4;
		}
		if(shu == 'A') {
			yz[pd][1] = 1;
		}else if(shu == 'T') {
			yz[pd][10] = 1;
		}else if(shu == 'J') {
			yz[pd][11] = 1;
		}else if(shu == 'Q') {
			yz[pd][12] = 1;
		}else if(shu == 'K') {
			yz[pd][13] = 1;
		}else {
			int js = shu-'0';
			yz[pd][js] = 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= 13; j++) {
			if(yz[i][j] == 0) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
} 
