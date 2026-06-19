#include <bits/stdc++.h>
using namespace std;
int n, q;
string a, b;
map<pair<string, string>, int> rp;
pair<string, string> get(string a, string b) {
	int s = 0, l = 0;
	for (int i = 0; i <= a.size(); i++)
		if (a[i] != b[i]) {
			s = i;
			break;
		}
	for (int i = a.size(); i >= 0; i--)
		if (a[i] != b[i]) {
			l = i - s + 1;
			break;
		}
	return {a.substr(s, l), b.substr(s, l)};
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	string s = "1123";
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		rp[get(a, b)]++;
	}
	for (int i = 1; i <= q; i++) {
		cin >> a >> b;
		if (a.size() != b.size()) cout << 0 << endl;
		else cout << rp[get(a, b)] << endl;
	}
	return 0;
}
