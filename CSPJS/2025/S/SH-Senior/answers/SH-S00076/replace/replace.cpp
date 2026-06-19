#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res;
}

#define endl "\n"
#define ull unsigned long long

const int N = 2e5 + 10, S = 5e6 + 10;
int n, q, ans[N];
struct Node {
	int tp;
	string s[2];
	ull hsh;
	int l, r;
	void gethsh() {
		l = s[0].length(), r = -1;
		for (int i = 0; i < s[0].length(); ++i)
			if (s[0][i] != s[1][i])
				l = min(l, i), r = max(r, i);
		hsh = 0;
		for (int i = l; i <= r; ++i)
			hsh = hsh * 131 + s[0][i];
		for (int i = l; i <= r; ++i)
			hsh = hsh * 131 + s[1][i];
	}
} s[N << 1];
inline bool comp(Node &x, Node &y) {
	return x.hsh < y.hsh;
}
map<int, int> tr[2][S];
int id[2][N], tot[2];
vector<int> vec[S];
vector<pair<int, int> > qry[S];
vector<int> to[2][S];
int dfn[N], dl[N], dr[N], timer;
bool spj[S];
void dfs1(int u) {
	if (spj[u]) dfn[u] = dl[u] = dr[u] = ++timer;
	for (int v : to[1][u]) {
		dfs1(v);
		dl[u] = min(dl[u], timer);
		dr[u] = max(dr[u], timer);
	}
}
int bit[N];
inline void add(int x) {
	while (x <= n) ++bit[x], x += x & (-x);
}
inline void del(int x) {
	while (x <= n) --bit[x], x += x & (-x);
}
inline int query(int x) {
	int res = 0;
	while (x) res += bit[x], x -= x & (-x);
	return res;
}
void dfs0(int u) {
	for (int x : vec[u])
		add(dl[x]), del(dr[x] + 1);
	for (pair<int, int> qr : qry[u])
		ans[qr.second] = query(dfn[qr.first]);
	for (int v : to[0][u]) dfs0(v);
	for (int x : vec[u]) 
		del(dl[x]), add(dr[x] + 1);
}
void solve(int l, int r) {
	if (s[l].hsh == 0 || l == r) return;
	for (int i = 1; i <= tot[0]; ++i) {
		vector<int> ().swap(vec[i]);
		vector<pair<int, int> > ().swap(qry[i]);
		vector<int> ().swap(to[0][i]);
		tr[0][i].clear();
	}
	for (int i = 1; i <= tot[1]; ++i) {
		vector<int> ().swap(to[1][i]);
		tr[1][i].clear();
		spj[i] = 0;
	}
	tot[0] = tot[1] = 1, timer = 0;
	for (int i = l; i <= r; ++i) {
		// cout << s[i].tp << " " << s[i].s[0] << " " << s[i].s[1] << endl;
		int u = 1;
		for (int j = s[i].l - 1; j >= 0; --j) {
			int ch = s[i].s[0][j] - 'a';
			if (tr[0][u][ch] == 0) {
				tr[0][u][ch] = ++tot[0];
				to[0][u].push_back(tot[0]);
			}
			u = tr[0][u][ch];
		}
		id[0][i] = u;
		u = 1;
		for (int j = s[i].r + 1; j < s[i].s[0].length(); ++j) {
			int ch = s[i].s[0][j] - 'a';
			if (tr[1][u][ch] == 0) {
				tr[1][u][ch] = ++tot[1];
				to[1][u].push_back(tot[1]);
			}
			u = tr[1][u][ch];
		}
		id[1][i] = u;
		spj[id[1][i]] = true;
		// cout << id[0][i] << " " << id[1][i] << endl;
		if (s[i].tp == 0) vec[id[0][i]].push_back(id[1][i]);
		else qry[id[0][i]].push_back(make_pair(id[1][i], s[i].tp));
	}
	dfs1(1), dfs0(1);
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].s[0] >> s[i].s[1];
		s[i].gethsh();
	}
	for (int i = n + 1; i <= n + q; ++i) {
		cin >> s[i].s[0] >> s[i].s[1], s[i].tp = i - n;
		s[i].gethsh();
	}
	sort(s + 1, s + n + q + 1, comp);
	for (int i = 1; i <= n + q; ++i) {
		int l = i, r = i;
		while (s[r].hsh == s[r + 1].hsh) ++r;
		solve(l, r), i = r;
	}
	for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
	return 0;
}