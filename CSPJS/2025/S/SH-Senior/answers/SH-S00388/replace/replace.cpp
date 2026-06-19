#include <iostream>
#include <map>

using namespace std;

int n, q, ans;
map<string, string> mp; 
string t1, t2;

void dfs(string s) {
	if (s == t2) {
		ans ++;
		return;
	}
	for (auto i : mp) {
		for (int j = 0; j < s.size(); j++)
			if (i.first == s.substr(j, i.first.size())) {
				string s0 = s.substr(0, j);
				string s1 = i.second;
				string s2 = s.substr(j + i.first.size());
				string ss = "";
				ss += s0;
				ss += s1;
				ss += s2;
				dfs(ss);
			}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	while (q--) {
		cin >> t1 >> t2;
		int ans = 0;
		dfs(t1);
		cout << ans << "\n";
	}
	return 0;
}
