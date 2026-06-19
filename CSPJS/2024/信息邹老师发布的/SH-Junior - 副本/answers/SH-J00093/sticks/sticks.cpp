#include<bits/stdc++.h>
using namespace std;
int num[10] = {6,2,5,5,4,5,6,3,7,6};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while (T --) {
		int n;
		cin >> n;
		if (n < 2) {cout << -1 << endl; continue; }
		if (n <= 7) {
			if (n == 3) cout << 7 << endl;
			if (n == 4) cout << 4 << endl;
			if (n == 5) cout << 2 << endl;
			if (n == 6) cout << 6 << endl;
			if (n == 7) cout << 8 << endl;
			continue;
		}
		string s = "";
		int w;
		int p = n / 7;
		if (n % 7 == 0) w = n / 7;
		else w = n / 7 + 1;
		int m = w * 7;
		
		//cout << n << " " << p << " " << w << " " << m << endl;
		 
		if (m - n >= 5) {
			s += '1';
			if (m - n == 6) {
				s += '0'; 
				for (int i = 1;i < w - 1;i ++) s += '8';
			}
			else for (int i = 1;i < w;i ++) s += '8';
		}
		else if (m - n >= 2) {
			s += '2';
			for (int i = 1;i <= (m - n) - 2;i ++) s += '0';
			for (int i = 1;i <= w - ((m - n) - 2) - 1;i ++) s += '8';
		}
		else if (m - n >= 1) {
			s += '6';
			for (int i = 1;i <= (m - n) - 2;i ++) s += '0';
			for (int i = 1;i <= w - ((m - n) - 2) - 2;i ++) s += '8';
		}
		else for (int i = 1;i <= w;i ++) s += '8';
		cout << s << endl;
	}
	return 0;
}
