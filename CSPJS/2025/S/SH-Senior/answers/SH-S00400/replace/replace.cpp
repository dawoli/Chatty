#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 200009;
int sz[N][3], n, q;
string s[N][4], t0, t1;
void sA() {
	for (int i = 1; i <= n; i++) {
		sz[i][0] = s[i][0].size();
		if (s[i][0] == s[i][1]) {
			s[i][2] = "";
			continue;
		}
		int l = 0, r = sz[i][0] - 1;
		while (s[i][0][l] == s[i][1][l]) l++;
		while (s[i][0][r] == s[i][1][r]) r--;
		sz[i][1] = l, sz[i][2] = r;
		s[i][2] = s[i][0].substr(l, r - l + 1);
		s[i][3] = s[i][1].substr(l, r - l + 1);
	}
	int ans = 0;
	cin >> t0 >> t1;
	if (t0.size() != t1.size()) {
		cout << 0;
		return;
	}
	int lth = t0.size(), l = 0, r = lth - 1;
	while (t0[l] == t1[l]) l++;
	while (t0[r] == t1[r]) r--;
	for (int i = 1; i <= n; i++) {
		if (s[i][2] != t0.substr(l, r - l + 1) || s[i][3] != t1.substr(l, r - l + 1)) continue;
		if (l < sz[i][1] || lth - r < sz[i][0] - sz[i][2]) continue;
		bool g = 1;
		for (int j = 0; j < sz[i][1]; j++) g = g && s[i][0][j] == t0[j + l - sz[i][1]];
		for (int j = sz[i][2]; j < sz[i][0]; j++) g = g && s[i][0][j] == t0[j + l - sz[i][1]];
		if (g) ans++;
	}
	cout << ans;
}
bool spc(string ss) {
	int cnt = 0;
	for (int i = 0; i < ss.size(); i++)
		if (ss[i] > 'b') return 0;
		else if (ss[i] == 'b') cnt++;
	return cnt == 1;
}
bool spcB() {
	bool ok = 1;
	for (int i = 1; i <= n; i++) ok = ok && spc(s[i][0]) && spc(s[i][1]);
	return ok;
}
void sB() {
	for (int i = 1; i <= n; i++) {
		sz[i][0] = s[i][0].size();
		int p1 = 0, p2 = 0;
		while (s[i][0][p1] == 'a') p1++;
		while (s[i][1][p2] == 'a') p2++;
		sz[i][1] = p1, sz[i][2] = p2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t0 >> t1;
		int p0 = 0, p1 = 0;
		while (t0[p0] == 'a') p0++;
		while (t1[p1] == 'a') p1++;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (p1 - p0 != sz[i][2] - sz[i][1]) continue;
			if (p0 >= sz[i][1] && t0.size() - p1 >= sz[i][0] - sz[i][2]) ans++;
		}
		cout << ans << endl;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	if (q == 1) sA();
	else if (spcB()) sB();
	return 0;
}
	
