#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define FOR(i, n, m) for(int i = (n); i <= (m); i ++)
#define ROF(i, n, m) for(int i = (n); i >= (m); i --)
#define REP(i, n) for(int i = 0; i < (n); i ++)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define FI(v) v.first
#define SE(v) v.second
#define SZ(v) int(v.size())
#define BG(v) v.begin()
#define ED(v) v.end()
#define ALL(v) BG(v), ED(v)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define SHOW(x) #x << " = " << x << " "
template < typename A , typename B >
inline bool chmax(A & x, B y) { return (x < y ? (x = y, true) : false); }
template < typename A , typename B >
inline bool chmin(A & x, B y) { return (x > y ? (x = y, true) : false); }
bool __ST__;
const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int P0 = 998244353;
const int P1 = 1e9 + 7;
const int B = 3331;
int n, q;
string s1[N], s2[N];
int tr[M][26], fail[M], idx;
int fi[M], ne[M], to[M], ecnt;
int dfn[M], sz[M], dfncnt;
vector<int> ed[M];
int rt[N], tot;
vector<PII> E[N];
vector<int> b[N];
map<pair<ull, ull>, int> mp;
vector<vector<PII>> F[N];
bool __ED__;
void add(int u, int v) {
	ne[++ ecnt] = fi[u];
	to[ecnt] = v;
	fi[u] = ecnt;
}
void insert(int id, string s, int x) {
	if(! rt[id]) rt[id] = ++ idx;
	int u = rt[id];
	for(char c : s) {
		int o = c - 'a';
		if(! tr[u][o]) tr[u][o] = ++ idx;
		u = tr[u][o];
	}
	E[id].eb(u, x);
}
void dfs(int u) {
	sz[u] = 1;
	dfn[u] = ++ dfncnt;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		dfs(v);
		sz[u] += sz[v];
	}
}
void build(int rt, int id) {
	queue<int> q;
	REP(i, 26) {
		if(tr[rt][i]) fail[tr[rt][i]] = rt, q.push(tr[rt][i]);
		else tr[rt][i] = rt;
	}
	while(! q.empty()) {
		int u = q.front(); q.pop();
		add(fail[u], u);
		REP(i, 26) {
			if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
			else tr[u][i] = tr[fail[u]][i];
		}
	}
	dfncnt = 0;
	dfs(rt);
	for(auto h : E[id]) b[id].pb(SE(h));
	sort(ALL(b[id]));
	b[id].erase(unique(ALL(b[id])), ED(b[id]));
	F[id].resize(SZ(b[id]));
	for(auto h : E[id]) {
		int u, x; tie(u, x) = h;
		x = lower_bound(ALL(b[id]), x) - BG(b[id]);
		F[id][x].pb({dfn[u], 1});
		F[id][x].pb({dfn[u] + sz[u], - 1});
	}
	REP(x, SZ(b[id])) {
		auto & FF = F[id][x];
		sort(ALL(FF));
		FOR(i, 1, SZ(FF) - 1) SE(FF[i]) += SE(FF[i - 1]);
	}
}
void solve() {
	// cerr << abs(& __ST__ - & __ED__) / 1e6 << " MB" << endl;
	cin >> n >> q;
	FOR(i, 1, n) {
		cin >> s1[i] >> s2[i];
		int sz = SZ(s1[i]);
		if(s1[i] == s2[i]) continue;
		else {
			int l = sz + 1, r = - 1;
			REP(j, sz) if(s1[i][j] != s2[i][j]) chmin(l, j), chmax(r, j);
			uint l0 = 0, l1 = 0, r0 = 0, r1 = 0;
			FOR(j, l, r) {
				l0 = (1ull * l0 * B + s1[i][j]) % P0;
				l1 = (1ull * l1 * B + s1[i][j]) % P1;
				r0 = (1ull * r0 * B + s2[i][j]) % P0;
				r1 = (1ull * r1 * B + s2[i][j]) % P1;
			}
			ull L = l0 << 30 ^ l1;
			ull R = r0 << 30 ^ r1;
			int plen = sz - l - 1;
			if(mp.count({L, R})) {
				insert(mp[{L, R}], s1[i], plen);
			}
			else {
				mp[{L, R}] = ++ tot;
				insert(tot, s1[i], plen); 
			}
		}
	}
	FOR(i, 1, tot) build(rt[i], i);
	REP(_, q) {
		string t1, t2;
		cin >> t1 >> t2;
		int sz = SZ(t1);
		int l = sz + 1, r = - 1;
		REP(i, sz) if(t1[i] != t2[i]) chmin(l, i), chmax(r, i);
		uint l0 = 0, l1 = 0, r0 = 0, r1 = 0;
		FOR(j, l, r) {
			l0 = (1ull * l0 * B + t1[j]) % P0;
			l1 = (1ull * l1 * B + t1[j]) % P1;
			r0 = (1ull * r0 * B + t2[j]) % P0;
			r1 = (1ull * r1 * B + t2[j]) % P1;
		}
		ull L = l0 << 30 ^ l1;
		ull R = r0 << 30 ^ r1;
		if(! mp.count({L, R})) {
			cout << 0 << endl;
			continue;
		}
		int pos = mp[{L, R}];
		int u = rt[pos];
		ll ans = 0;
		REP(i, sz) {
			int o = t1[i] - 'a';
			u = tr[u][o];
			if(i < r) continue;
			int x = i - l;
			if(b[pos].empty()) continue;
			if(x < b[pos][0]) continue;
			if(b[pos].back() < x) continue;
			int v = lower_bound(ALL(b[pos]), x) - BG(b[pos]);
			if(b[pos][v] != x) continue;
			auto & FF = F[pos][v];
			if(FF.empty()) continue;
			if(dfn[u] < FI(FF[0])) continue;
			int L = 0, R = SZ(FF) - 1, ppos = 0;
			while(L <= R) {
				int mid = L + R >> 1;
				if(FI(FF[mid]) <= dfn[u]) ppos = mid, L = mid + 1;
				else R = mid - 1;
			}
			ans += SE(FF[ppos]);
		}
		cout << ans << endl;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}