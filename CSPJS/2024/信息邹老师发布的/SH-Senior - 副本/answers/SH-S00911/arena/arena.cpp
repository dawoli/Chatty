#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define ld long double
#define int128 __int128
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define ROF(i,n,m) for(int i=(n);i>=(m);i--)
#define REP(i,n) for(int i=0;i<(n);i++) 
#define SZ(v) v.size()
#define PII pair<int, int>
#define FI(v) v.first
#define SE(v) v.second
#define BG(v) v.begin()
#define ED(v) v.end()
#define ALL(V) BG(v), ED(v)
#define endl '\n'
template < typename A , typename B >
inline bool chmax(A &x, B y) { return (x < y ? (x = y, true) : false); }
template < typename A , typename B >
inline bool chmin(A &x, B y) { return (x > y ? (x = y, true) : false); }
const int N = 2e5 + 5;
const int M = 2e6 + 5;
int n, m, s, c, lg[M], lw[M];
int af[N], a[N], X[4];
string d[100];
vector<int> e[N];
struct Node {
	ll T, S[20]; int B;
};
vector<Node> t[20];
inline void insert(Node &h, int u, ll x) {
	if(!(h.B >> u & 1)) {
		h.B |= (1 << u);
		h.S[u] = x;
	}
	else {
		h.S[u] += x;
	}
}
int lowbit(int x) {
	return - x & x;
}
inline void pushup(int u, int y) {
	int ls = (u << 1) - 1;
	int rs = u << 1;
	if(d[y][u] == '1') {
		swap(ls, rs);
	}
	t[y + 1][u].T = t[y + 1][u].B = 0;
	bool ok = 0;
	int bt = t[y][ls].B;
	while(bt) {
		int lst = lw[bt];
		bt ^= lst;
		int j = lg[lst];
		if(j > y) insert(t[y + 1][u], j, t[y][ls].S[j]);
		else ok = 1;
	}
	if(t[y][ls].T) {
		t[y + 1][u].T += t[y][ls].T;
		ok = 1;
	}
	if(ok) {
		int bt = t[y][rs].B;
		while(bt) {
			int lst = lw[bt];
			bt ^= lst;
			int j = lg[lst];
			insert(t[y + 1][u], j, t[y][rs].S[j]);
		}
		t[y + 1][u].T += t[y][rs].T;
	}
}
void slv() {
	ll ans = 0;
	FOR(i, 1, s) {
		t[0][i].T = i;
		t[0][i].B = 0;
	}
	int sz = 1, ht = 0, llen = s;
	while(sz < n) {
		sz <<= 1, ht ++; llen >>= 1;
		FOR(i, 1, llen) pushup(i, ht - 1);
	}
	sz = 1, ht = 0;
	FOR(i, 1, n) {
		t[0][i].T = 0;
		int u = (a[i] >= 19 ? 19 : a[i]);
		insert(t[0][i], u, i);
		while(sz < i) sz <<= 1, ht ++;
		int pos = i;
		REP(j, ht) {
			pos = (pos + 1) >> 1;
			pushup(pos, j);
		}
		ll val = t[ht][1].T;
		int bt = t[ht][1].B;
		while(bt) {
			int lst = lw[bt];
			bt ^= lst;
			int j = lg[lst];
			val += t[ht][1].S[j];
		}
		for(int id : e[i]) ans ^= (1ll * id * val);
	}
	cout << ans << endl;
}
void solve() {
	cin >> n >> m;
	FOR(i, 1, n) cin >> af[i];
	FOR(i, 1, m) {
		int x; cin >> x;
		e[x].push_back(i);	
	}
	s = 1, c = 0;
	while(s < n) s <<= 1, c ++;
	int sz = 1, ht = 0, llen = s;
	t[0].resize(s + 1);
	while(sz < n) {
		sz <<= 1, ht ++; llen >>= 1;
		t[ht].resize(llen + 1);
	}
	REP(i, c) {
		cin >> d[i]; 
		d[i] = ' ' + d[i];	
	}
	REP(i, M) lw[i] = lowbit(i);
	REP(i, 22) {
		int u = 1 << i;
		if(u < M) lg[u] = i;
	}
	int T; cin >> T;
	REP(_, T) {
		REP(i, 4) cin >> X[i];
		FOR(i, 1, n) a[i] = af[i] ^ (X[i % 4]);
		slv();
	}
}
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

