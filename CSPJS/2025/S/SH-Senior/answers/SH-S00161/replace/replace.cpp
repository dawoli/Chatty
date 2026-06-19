#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
namespace IANYEYZ {
	int n, q;
	string s[200010][3], t[200010][3];
	int val[200010];
	int fi[200010], se[200010];
	void solve() {
		cin >> n >> q;
		int l1 = 0;
		rep (i, 1, n) {
			cin >> s[i][1] >> s[i][2];
			l1 += s[i][1].size() + s[i][2].size();
		}
		rep (i, 1, q) {
			cin >> t[i][1] >> t[i][2];
		}
		if (n <= 1 && l1 <= 2000) {
			rep (i, 1, n) {
				rep (j, 0, s[i][1].size()) {
					if (s[i][1][j] != s[i][2][j]) {
						val[i] = j;
						break;
					}
				}
			}
			rep (i, 1, q) {
//				cout << t[i][1] << " " << t[i][2] << "\n";
				int flag = 0;
				rep (j, 0, t[i][1].size()) {
					if (t[i][1][j] != t[i][2][j]) {
						flag = j;
						break;
					}
				}
				int res = 0;
				rep (j, 1, n) {
					int l = flag - val[j], len = s[j][1].size();
					if (l < 0) continue;
					if (t[i][1].substr(l, len) != s[j][1]) continue;
					string te = t[i][1];
					rep (k, l, l + len - 1) {
						t[i][1][k] = s[j][2][k - l];
					}
					// cout << i << " " << j << " " << val[j] << " " << flag << " " << l << " " << len << " " << t[i][1] << " " << t[i][2] << "\n";
					res += t[i][1] == t[i][2];
					t[i][1] = te;
				}
				cout << res << "\n";
			}
		} else {
			map<int, vector<int> > mp;
			rep (i, 1, n) {
				rep (j, 0, s[i][1].size() - 1) {
					if (s[i][1][j] == 'b') {
						fi[i] = j;
					}
				}
				rep (j, 0, s[i][2].size() - 1) {
					if (s[i][2][j] == 'b') {
						se[i] = j;
					}
				}
				mp[se[i] - fi[i]].push_back(i);
			}
			rep (i, 1, q) {
				int f1 = 0, s1 = 0, res = 0;
				rep (j, 0, t[i][1].size() - 1) {
					if (t[i][1][j] == 'b') {
						f1 = j;
					}
				}
				rep (j, 0, t[i][2].size() - 1) {
					if (t[i][2][j] == 'b') {
						s1 = j;
					}
				}
				for (auto j:mp[s1 - f1]) {
					if (fi[j] <= f1 && (s[j][1].size() - se[j]) <= (t[i][1].size() - s1)) {
						res++;
					}
				}
				cout << res << "\n";
			}
		}
	}
}
int main() {
	cin.tie(0) -> ios :: sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	IANYEYZ :: solve();
}
