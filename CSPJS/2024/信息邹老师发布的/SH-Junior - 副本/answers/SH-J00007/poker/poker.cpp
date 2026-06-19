#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string t,
num[52] = 
	{"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"}, 
h[4] = 
	{"D", "C", "H", "S"};
map<string, bool> a;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t] = true;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (!a[h[i] + num[j]]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
