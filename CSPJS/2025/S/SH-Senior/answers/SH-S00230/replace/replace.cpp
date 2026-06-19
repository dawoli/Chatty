#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[200002], s2[200002];
string q1, q2;
struct node {
	string v;
	bool w;
};
map <string, node> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		mp[s1[i]] = {s2[i], 1};
	}
	while (q--) {
		cin >> q1 >> q2;
		if (q1.size() != q2.size()) {
			cout << "0\n";
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s1[i].size() > q1.size()) continue;
			int s = q1.find(s1[i]);
			if (s < 0 || q2.substr(s, s2[i].size()) != s2[i]) continue;
			string x = q1.substr(0, s), z = q1.substr(s + s1[i].size());
			if (x + s2[i] + z == q2) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
