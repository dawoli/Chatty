#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int n, q, ans;
string a, b;
pair<string, string> d[maxn];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> d[i].first >> d[i].second;
	}
	while (q--) {
		ans = 0;
		cin >> a >> b;
		for (int i = 0; i < n; i++) {
			string u = d[i].first, v = d[i].second;
			string x, z, tmp;
			if (u.size() > a.size()) continue;
			for (int j = 0; j <= a.size() - u.size(); j++) {
				if (a.substr(j, u.size()) == u) {
					x = a.substr(0, j);
					z = a.substr(j + u.size(), a.size() - j - u.size());
					tmp = x + v + z;
					if (tmp == b) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
