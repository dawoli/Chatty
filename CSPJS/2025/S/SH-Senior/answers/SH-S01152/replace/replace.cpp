#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 4e5 + 5;
const int dis = 1e7;
int n, q;
string s[maxn][2];
string t[maxn][2];
void Read() {
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= n; i ++) cin >> t[i][0] >> t[i][1];
}
namespace B {
	bool fe() {
		bool flag;
		for (int i = 1; i <= n; i ++) {
			flag = false;
			for (auto it: s[i][0]) {
				if (it != 'a' && it != 'b') return false;
				else if (it == 'b') {
					if (flag) return false;
					flag = true;
				}
			}
			if (!flag) return false;
			flag = false;
			for (auto it: s[i][1]) {
				if (it != 'a' && it != 'b') return false;
				else if (it == 'b') {
					if (flag) return false;
					flag = true;
				}
			}
			if (!flag) return false;
		}
		for (int i = 1; i <= q; i ++) {
			flag = false;
			for (auto it: t[i][0]) {
				if (it != 'a' && it != 'b') return false;
				else if (it == 'b') {
					if (flag) return false;
					flag = true;
				}
			}
			if (!flag) return false;
			flag = false;
			for (auto it: t[i][1]) {
				if (it != 'a' && it != 'b') return false;
				else if (it == 'b') {
					if (flag) return false;
					flag = true;
				}
			}
			if (!flag) return false;
		}
		return true;
	}
	map<int, vector<int>> d;
	void Solve() {
		for (int i = 1; i <= n; i ++) {
			int d1, d2;
			for (int j = 0; j < s[i][0].size(); j ++) if (s[i][0][j] == 'b') d1 = j;
			for (int j = 0; j < s[i][1].size(); j ++) if (s[i][1][j] == 'b') d2 = j;
			d[d2 - d1].push_back(s[i][0].size());
		}
		for (int i = 0; i <= n << 1; i ++) sort(d[i].begin(), d[i].end())/*, d[i].push_back(1e7)*/;
		for (int i = 1; i <= q; i ++) {
			int d1, d2;
			for (int j = 0; j < t[i][0].size(); j ++) if (t[i][0][j] == 'b') d1 = j;
			for (int j = 0; j < t[i][1].size(); j ++) if (t[i][1][j] == 'b') d2 = j;
			int z = t[i][0].size();
//				for (auto it: d[dv]) cerr << it << ' ';
//				cerr << '\n';
				auto &v = d[d2 - d1];
				if (v.empty()) {
					cout << "0\n";
					continue;
				}
				auto it = upper_bound(v.begin(), v.end(), z);
				cout << max(it - v.begin(), 0ll) << '\n';
		}
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	Read();
	B::Solve();
}
