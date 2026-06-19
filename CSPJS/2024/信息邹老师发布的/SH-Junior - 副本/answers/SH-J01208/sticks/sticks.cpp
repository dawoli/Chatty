#include <bits/stdc++.h>
using namespace std;
int t;
int n;
string f[100010];
int a[10] = {6, 2, 5, 1e9, 4, 1e9, 6, 3, 7, 1e9};
bool cmp(string a, string b) {
	if (a.size() > b.size()) return 1;
	if (a.size() < b.size()) return 0;
	return a > b;
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i <= n; i++) {
			f[i] = "1000000000";
		}
		f[2] = "1";
		f[5] = "2";
		f[4] = "4";
		f[6] = "6";
		f[3] = "7";
		f[7] = "8";
		for (int i = 0; i <= 9; i++) {
			for (int j = n; j >= max(a[i], 2); j--) {
				if (cmp(f[j], f[j - a[i]] + (char)('0' + i))) {
					f[j] = f[j - a[i]] + (char)('0' + i);
				}
			}
		}
		if (f[n] == "1000000000") cout << -1 << endl;
		else cout << f[n] << endl;
	}
	return 0;
} 
