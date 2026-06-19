#include <bits/stdc++.h>
using namespace std;
bool c[15], d[15], h[15], ss[15];
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin >> s;
		if(s[0] == 'C'){
			if(s[1] >='2' && s[1] <= '9'){
				c[s[1] - '0'] = 1;
			}
			if(s[1] == 'T'){
				c[10] = 1;
			}
			if(s[1] == 'J'){
				c[11] = 1;
			}
			if(s[1] == 'Q'){
				c[12] = 1;
			}
			if(s[1] == 'K'){
				c[13] = 1;
			}
			if(s[1] == 'A'){
				c[14] = 1;
			}
		}
		if(s[0] == 'D'){
			if(s[1] >='2' && s[1] <= '9'){
				d[s[1] - '0'] = 1;
			}
			if(s[1] == 'T'){
				d[10] = 1;
			}
			if(s[1] == 'J'){
				d[11] = 1;
			}
			if(s[1] == 'Q'){
				d[12] = 1;
			}
			if(s[1] == 'K'){
				d[13] = 1;
			}
			if(s[1] == 'A'){
				d[14] = 1;
			}
		}
		if(s[0] == 'H'){
			if(s[1] >='2' && s[1] <= '9'){
				h[s[1] - '0'] = 1;
			}
			if(s[1] == 'T'){
				h[10] = 1;
			}
			if(s[1] == 'J'){
				h[11] = 1;
			}
			if(s[1] == 'Q'){
				h[12] = 1;
			}
			if(s[1] == 'K'){
				h[13] = 1;
			}
			if(s[1] == 'A'){
				h[14] = 1;
			}
		}
		if(s[0] == 'S'){
			if(s[1] >='2' && s[1] <= '9'){
				ss[s[1] - '0'] = 1;
			}
			if(s[1] == 'T'){
				ss[10] = 1;
			}
			if(s[1] == 'J'){
				ss[11] = 1;
			}
			if(s[1] == 'Q'){
				ss[12] = 1;
			}
			if(s[1] == 'K'){
				ss[13] = 1;
			}
			if(s[1] == 'A'){
				ss[14] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 2 ; i <= 14 ; i++){
		if(c[i] == 0){
			cnt++;
		}
	}
	for(int i = 2 ; i <= 14 ; i++){
		if(h[i] == 0){
			cnt++;
		}
	}
	for(int i = 2 ; i <= 14 ; i++){
		if(d[i] == 0){
			cnt++;
		}
	}
	for(int i = 2 ; i <= 14 ; i++){
		if(ss[i] == 0){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
