#include <bits/stdc++.h>
using namespace std;
int n, q, ans[200010];
string s[200010][2], t[2];
inline bool check(string src, string des, string origin, string rep) {
	int ls = src.length(), lr = origin.length();
	if(!lr) return false;
	for(int i = 0; i <= ls - lr; ++i) {
		string tmp = src;
		bool flag = false;
		for(int j = i; j < i + lr; ++j) {
			if(tmp[j] != origin[j - i]) flag = true;
			else tmp[j] = rep[j - i];
		}
		if(flag) continue;
		if(tmp == des) return true;
	}
	return false;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i][0] >> s[i][1];
		if(s[i][0] == s[i][1]) {
			s[i][0] = "";
			s[i][1] = "";
			continue;
		}
	}
	for(int i = 0; i < q; ++i) {
		cin >> t[0] >> t[1];
		for(int j = 1; j <= n; ++j) {
			if(check(t[0], t[1], s[j][0], s[j][1])) ++ans[i];
		}
	}
	for(int i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}
