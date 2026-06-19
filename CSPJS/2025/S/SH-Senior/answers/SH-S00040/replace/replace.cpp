#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, r, l) for (int i = (r); i >= (l); --i)
using namespace std;

int n, q, ans;
string s1, s2;

map<string, string> mp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	rep (i, 1, n) {
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	rep (i, 1, q) {
		ans = 0;
		cin >> s1 >> s2;
		for (int j = 0; j < static_cast<int>(s1.size()); ++j) {
			for (int k = j; k < static_cast<int>(s1.size()); ++k) {
				string sub = s1.substr(j, k - j + 1);
				if (mp.find(sub) != mp.end()) {
					if (s1.substr(0, j - 1) + mp[sub] + s1.substr(j + 1) == s2) {
						++ans;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
