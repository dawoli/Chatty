#include <bits/stdc++.h>
using namespace std;
int n, q, pos1[200005], pos2[200005];
string pre[200005], lst[200005];
struct node {
	string s1, s2;
} s[200005];
bool cmp(node x, node y) {
	return x.s1.size() < y.s1.size();
}
void solve() {
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
		for (int j = 0; j < s[i].s1.size(); j++) {
			if (s[i].s1[j] == 'b') {
				pos1[i] = j;
				break;
			}
		}
		for (int j = 0; j < s[i].s2.size(); j++) {
			if (s[i].s2[j] == 'b') {
				pos2[i] = j;
				break;
			}
		}
	}
	while (q--) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			cout << 0 << endl;
			continue;
		}
		int p1 = -1, p2 = -1;
		for (int i = 0; i < x.size(); i++) {
			if (x[i] == 'b') {
				p1 = i;
				break;
			}
		}
		for (int i = 0; i < y.size(); i++) {
			if (y[i] == 'b') {
				p2 = i;
				break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (pos1[i] - pos2[i] == p1 - p2 && pos1[i] <= p1 && x.size() - p1 >= s[i].s1.size() - pos1[i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	if (n > 100) {
		solve();
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> s[i].s1 >> s[i].s2;
	sort(s + 1, s + n + 1, cmp);
	while (q--) {
		string x, y; cin >> x >> y;
		int l1 = x.size(), l2 = y.size();
		x = " " + x;
		pre[0] = "";
		lst[l1 + 1] = "";
		for (int i = 1; i <= l1; i++) pre[i] = pre[i - 1] + x[i];
		for (int i = l1; i >= 1; i--) lst[i] = lst[i + 1] + x[i];
		if (l1 != l2) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int j = 1; j <= l1; j++) {
			string temp = "";
			int l = j - 1;
			for (int i = 1; i <= n; i++) {
				if (j + s[i].s1.size() - 1 > l1) break;
				for (int k = l + 1; k <= j + s[i].s1.size() - 1; k++) temp += x[k];
				l = j + s[i].s1.size() - 1;
				if (temp != s[i].s1) continue;
				string tt = pre[j - 1] + s[i].s2 + lst[j + s[i].s1.size()];
				if (tt == y) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
