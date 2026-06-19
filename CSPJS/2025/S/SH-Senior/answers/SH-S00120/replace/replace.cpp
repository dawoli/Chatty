#include <bits/stdc++.h>
using namespace std;
map<string, string> rp;
set<int> len;
string s[200005];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		rp[s1] = s2;
		s[i] = s1;
		len.insert(s1.length());
	}
	while(q--) {
		string t1, t2, t3;
		cin >> t1 >> t2;
		if (t1.length() != t2.length()) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		if (t1.length() > 200) {
			int b1, b2, b3, b4;
			b1 = t1.find('b');
			b2 = t2.find('b');
			for (int j = 1; j <= n; j++) {
				b3 = s[j].find('b');
				b4 = rp[s[j]].find('b');
				if (b1-b2 == b3-b4 && b1-b3+s[j].length() <= t1.length()) ans++;
			}
			cout << ans << endl;
			continue;
		}
		for (int l : len) {
			if (l > t1.length()) continue;
			for (int i = 0; i <= t1.length() - l; i++) {
				t3 = "";
				for (int j = i; j < i + l; j++) t3 += t1[j];
				for (int k = 1; k <= n; k++) {
					if (s[k] == t3) {
						t1.replace(i, l, rp[s[k]]);
						if (t1 == t2) ans++;
						t1.replace(i, l, s[k]);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
