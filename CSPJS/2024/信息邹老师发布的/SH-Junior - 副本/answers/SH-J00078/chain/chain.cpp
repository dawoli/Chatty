#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int t, n, k, r, flag;
char c;
string s[N];

void dfs(int step, int id, string a) {
	if (step > r) {
		if (a[a.size() - 1] == c) flag = 1;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (i == id) continue;
		if (a == "") {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == '1') {
					for (int l = 2; l <= k && j + l - 1 <= n; l++) {
						string w = s[i].substr(j, l);
						dfs(step + 1, i, w);
					}
				}
			}
		} else {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == a[a.size() - 1]) {
					for (int l = 2; l <= k && j + l - 1 <= n; l++) {
						string w = s[i].substr(j, l);
						dfs(step + 1, i, w);
					}
				}
			}
		}
	}
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while (t--) {
		int q;
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++) {
			int l;
			cin >> l;
			for (int j = 1; j <= l; j++) {
				int x;
				cin >> x;
				s[i] += x + '0';
			}
		}
		while (q--) {
			cin >> r >> c;
			flag = 0;
			for (int i = 1; i <= n; i++) dfs(1, i, "");
			cout << flag << endl;
		}
	}
	return 0;
} 
