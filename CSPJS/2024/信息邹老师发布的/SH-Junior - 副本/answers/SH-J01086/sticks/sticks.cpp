#include <bits/stdc++.h>
using namespace std; 
const int cnt [10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int k [18] = {0, -1, 1, 7, 4, 2, 6, 8, 16, 18, 22, 20, 28, 80, 88, 108, 188};
string make (int a, char b) {
	string ans = "";
	for (int i = 1; i <= a; i ++) ans += b;
	return ans;
}
string c (string a, string b) {return a + b;}
string ans (int a) { 
	int num = a / 7; 
	if (a % 7 == 0) return make (num, '8');
	int re = a % 7;
	// cout << re << endl; 
	if (re == 1) return c("10", make (num - 1, '8'));
	if (re == 2) return c("1", make (num, '8'));
	if (re == 3) return c("200", make (num - 2, '8'));
	if (re == 4) return c("20", make (num - 1, '8'));
	if (re == 5) return c("2", make (num, '8'));
	if (re == 6) return c("6", make (num, '8')); 
	return "-1";
}
int main () { 
	freopen ("sticks.in", "r", stdin);
	freopen ("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		if (n <= 17) cout << k [n];
		else cout << ans (n);
		cout << endl;
	}
}