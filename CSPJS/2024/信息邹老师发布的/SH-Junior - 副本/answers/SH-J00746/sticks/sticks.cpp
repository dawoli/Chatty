#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long f[N][210]; 
int main () {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	for(int i = 0; i <= 1e5; i ++) {
		for(int j = 0; j <= 200; j ++) {
			f[i][j] = 1e12;
		}
	}
	f[0][1] = 1e12;
	f[1][1] = 1e12;
	f[2][1] = 1;
	f[3][1] = 7;
	f[4][1] = 4;
	f[5][1] = 2;
	f[6][1] = 6;
	f[7][1] = 8;
	for(int i = 1; i <= 1e5; i ++) {
		for(int j = 1; j <= 200; j ++) {
			if(i>=6) f[i][j] = min(f[i][j], f[i-6][j-1]*10 + 0);
			if(i>=2) f[i][j] = min(f[i][j], f[i-2][j-1]*10 + 1);
			if(i>=5) f[i][j] = min(f[i][j], f[i-5][j-1]*10 + 2);
			if(i>=5) f[i][j] = min(f[i][j], f[i-5][j-1]*10 + 3);
			if(i>=4) f[i][j] = min(f[i][j], f[i-4][j-1]*10 + 4);
			if(i>=5) f[i][j] = min(f[i][j], f[i-5][j-1]*10 + 5);
			if(i>=6) f[i][j] = min(f[i][j], f[i-6][j-1]*10 + 6);
			if(i>=3) f[i][j] = min(f[i][j], f[i-3][j-1]*10 + 7);
			if(i>=7) f[i][j] = min(f[i][j], f[i-7][j-1]*10 + 8);
			if(i>=6) f[i][j] = min(f[i][j], f[i-6][j-1]*10 + 9);
		}
	}
	/*for(int i = 1; i <= 50; i ++) {
		for(int j = 1; j <= 12; j ++) {
			cout << "f(" << i << "," << j << ")=";
			if(f[i][j] == 1e12) cout << -1 << ' ';
			else cout << f[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		long long ans = 1e12;
		for(int j = 1; j <= 12; j ++) {
			ans = min(ans, f[n][j]);
		}
		if(n >= 100) {
			if(n % 7 == 0) {
				for(int j = 1; j <= n/7; j ++) {
					cout << 8;
				}
				cout << endl;
			}
			else if(n % 7 == 1) {
				cout << "10";
				for(int j = 1; j <= n/7-1; j ++) {
					cout << 8;
				}
				cout << endl;
			}
			else cout << -1 << endl;
		}
		else{
			if(ans == 1e12) {
				cout << -1 << endl;
			}
			else cout << ans << endl;
		} 
		
	}
	
	return 0;
} 
