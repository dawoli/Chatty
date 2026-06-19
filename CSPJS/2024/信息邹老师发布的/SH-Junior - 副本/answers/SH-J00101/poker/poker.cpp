#include <iostream>
using namespace std;
int n;
struct Poker{
	char p[5];
}poker[65];
int pai[6][15];
int main () {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> poker[i].p;
	}
	if (n == 1) {
		cout << 51 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		char h, d;
		int ansx, ansy;
		ansx =  ansy = 0;
		h = poker[i].p[0];
		d = poker[i].p[1];
		if (h == 'D') {
			ansx = 0;
		}else if (h == 'C') {
			ansx = 1;
		}else if (h == 'H') {
			ansx = 2;
		}else if (h == 'S') {
			ansx = 3;
		}
		
		int t = d - 'A';
		if (t < 0) {
			t = d - '0';
		}else {
			if(d == 'A'){
				t = 1;
			}else if (d == 'J') {
				t = 11;
			}else if (d == 'Q') {
				t = 12;
			}else if (d == 'K') {
				t = 13;
			}else {
				t = 10;
			}
		}
		pai[ansx][t] ++;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			if(pai[i][j] == 0) {
				ans ++;
			}
		}
	}
	cout << ans;
	return 0;
}

/*


*/
