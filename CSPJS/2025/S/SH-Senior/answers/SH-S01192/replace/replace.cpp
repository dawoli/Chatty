#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[10001][3];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (t2.find(s[i][2]) == -1) continue;
			else {
				// s.replace(s.find(border), border.size(), "hhh");
				string rt = t1;
				if (rt.find(s[i][1]) == -1) continue;
				else {
					rt.replace(rt.find(s[i][1]), s[i][1].size(), s[i][2]);
					if (rt == t2) ans++; 
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
