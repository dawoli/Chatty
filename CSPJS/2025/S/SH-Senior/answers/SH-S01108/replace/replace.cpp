#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
string a[200005], b[200005], t, tt;
vector <int> e[1000006];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		e[a[i].length()].push_back(i);
	}
	while (q--) {
		cin >> t >> tt;
		int flag = 0, ans = 0;
		for (int i = 0; i < t.length(); ++i) {
			if (t[i] != tt[i]) {
				if (!flag) l = i, flag = 1;
				r = i;
			}
		}
//		cout << l << " " << r << "\n";
		for (int i = 0; i < t.length(); ++i) {
			for (int j = 0; j <= i; ++j) {
				if (j > l || i < r) continue;
//				cout << j << " " << i << "\n";
				if (e[i - j + 1].size() > 0) {
					for (int k = 0; k < e[i - j + 1].size(); ++k) 
						if (a[e[i - j + 1][k]] == t.substr(j, i - j + 1) && b[e[i - j + 1][k]] == tt.substr(j, i - j + 1)) ++ans;
//					cout << a[e[i - j + 1][0]] << " " << t.substr(j, i - j + 1) << " " << b[e[i - j + 1][0]] << " " << tt.substr(j, i - j + 1) << " " << ans << "\n";
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

