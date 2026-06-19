#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, cnt;
map<string, int> used;

signed main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (!used[s]) {
			cnt++;
			used[s] = 1;
		}
	}
	cout << 52 - cnt << endl;
	return 0;
} 
