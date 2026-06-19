#include <bits/stdc++.h>
using namespace std;
const int _ = 5666666;
inline pair<string, string> asdf(string s, string t) {
	int n = s.length();
	int a = 0;
	while (a < n && s[a] == t[a]) a++;
	int b = 0;
	while (b < n && s[n-b-1] == t[n-b-1]) b++;
	string u, v;
	if (a == n && b == n) {
		v = s;
	} else {
		u = s.substr(a, n-a-b) + t.substr(a, n-a-b);
		v = s.substr(0, a) + "`" + s.substr(n-b, b);
	}
	return make_pair(u, v);
}
int n, q, ctrie = 1, cval, trie[_][27], id[_];
inline int insid(string str) {
	int pos = 1;
	for (char c: str) {
		int s = c - 96;
		if (!trie[pos][s]) {
			trie[pos][s] = ++ctrie;
		}
		pos = trie[pos][s];
	}
	if (!id[pos]) {
		id[pos] = ++cval;
	}
	return id[pos];
}
inline int getid(string str) {
	int pos = 1;
	for (char c: str) {
		int s = c - 96;
		if (!trie[pos][s]) {
			return 0;
		}
		pos = trie[pos][s];
	}
	return id[pos];
}
vector<string> arr[200010];
int rt[200010], cac, ac[_][27], cnt[_], fa[_], fal[_];
bool vis[_];
int cntvis, posvis[_];
inline bool visit(int x) {
	if (vis[x]) {
		return true;
	} else {
		posvis[++cntvis] = x;
		vis[x] = true;
		return false;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s, t;
		cin >> s >> t;
		auto p = asdf(s, t);
		string u = p.first;
		string v = p.second;
		arr[insid(u)].push_back(v);
	}
	for (int i = 1; i <= cval; i++) {
		int r = ++cac;
		rt[i] = r;
		for (string str: arr[i]) {
			int p = r;
			for (char c: str) {
				int s = c - 96;
				if (!ac[p][s]) {
					ac[p][s] = ++cac;
					fa[cac] = p;
				}
				p = ac[p][s];
			}
			cnt[p]++;
		}
		queue<int> Q;
		fal[r] = r;
		for (int s = 0; s <= 26; s++) {
			if (ac[r][s]) {
				fal[ac[r][s]] = r;
				Q.push(ac[r][s]);
			} else {
				ac[r][s] = r;
			}
		}
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for (int s = 0; s <= 26; s++) {
				if (ac[u][s]) {
					fal[ac[u][s]] = ac[fal[u]][s];
					Q.push(ac[u][s]);
				} else {
					ac[u][s] = ac[fal[u]][s];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		string s, t;
		cin >> s >> t;
		auto p = asdf(s, t);
		string u = p.first;
		string v = p.second;
		int x = getid(u);
		if (!x) {
			cout << 0;
		} else {
			int r = rt[x];
			int p = r;
			visit(r);
			for (char c: v) {
				int s = c - 96;
				p = ac[p][s];
				int z = p;
				while (!visit(z)) z = fal[z];
			}
			int ans = 0;
			for (int i = 1; i <= cntvis; i++) {
				int k = posvis[i];
				ans += cnt[k];
				vis[k] = false;
			}
			cout << ans;
			cntvis = 0;
		}
		if (i != q) {
			cout << '\n';
		}
	}
	cout << endl;
	return 0;
}
