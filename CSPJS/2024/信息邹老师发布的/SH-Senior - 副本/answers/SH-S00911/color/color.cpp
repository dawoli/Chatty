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
const ll LNF = 1e18 + 117;
int n, a[N], b[N], len;
struct SgT {
	int le[N << 2], ri[N << 2];
	ll F[N << 2], T[N << 2];
	void pushup(int u) {
		F[u] = max(F[u << 1], F[u << 1 | 1]);
	}
	void push(int u, ll x) {
		F[u] += x;
		T[u] += x;
	}
	void pushdown(int u) {
		if(T[u]) {
			push(u << 1, T[u]);
			push(u << 1 | 1, T[u]);
			T[u] = 0;
		}
	}
	void build(int u, int l, int r) {
		le[u] = l, ri[u] = r;
		T[u] = 0;
		if(l == r) {
			F[u] = (l ? - LNF : 0);
			return;
		}
		int mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
	void modify(int u, int p, ll x) {
		if(le[u] == ri[u]) {
			chmax(F[u], x);
			return;
		}
		pushdown(u);
		int mid = le[u] + ri[u] >> 1;
		if(p <= mid) modify(u << 1, p, x);
		else modify(u << 1 | 1, p, x);
		pushup(u);
	}
	ll query(int u, int p) {
		if(le[u] == ri[u]) {
			return F[u];
		}
		pushdown(u);
		int mid = le[u] + ri[u] >> 1;
		if(p <= mid) return query(u << 1, p);
		else return query(u << 1 | 1, p);
	}
} t;
void solve() {
	cin >> n; len = 0;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) b[++len] = a[i];
	sort(b + 1, b + len + 1);
	len = unique(b + 1, b + len + 1) - b - 1;
	FOR(i, 1, n) a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
	t.build(1, 0, len);
	FOR(i, 1, n) {
		ll val = t.F[1];
		chmax(val, t.query(1, a[i]) + b[a[i]]);
		if(a[i] == a[i - 1]) t.push(1, b[a[i]]);
		t.modify(1, a[i - 1], val);
	}
	cout << t.F[1] << endl;
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
