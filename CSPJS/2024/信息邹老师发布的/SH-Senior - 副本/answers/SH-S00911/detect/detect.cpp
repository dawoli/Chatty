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
const int N = 1e5 + 5;
int n, m;
ll s, mx, pl[N], vx[N], ax[N], ps[N];
struct Node {
	int l, r;
	bool operator < (const Node & A) const {
		return r < A.r;
	}
} a[N]; int tot;
ll gv2(int i, int u) {
	if(ps[u] < pl[i]) return 0;
	ll val = 2 * ax[i] * (ps[u] - pl[i]) + vx[i] * vx[i];
	if(val < 0) return 0;
	return val;
}
int gf(int i) {
	int L = 1, R = m, res = - 1;
	while(L <= R) {
		int mid = L + R >> 1;
		if(pl[i] <= ps[mid]) {
			res = mid;
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	return res;
}
void solve() {
	cin >> n >> m >> s >> mx;
	FOR(i, 1, n) cin >> pl[i] >> vx[i] >> ax[i];
	FOR(i, 1, m) cin >> ps[i];
	int sum = 0, ans = 0; tot = 0;
	FOR(i, 1, n) {
		if(ax[i] >= 0) {
			int L = 1, R = m, res = - 1;
			while(L <= R) {
				int mid = L + R >> 1;
				ll val = gv2(i, mid);
				if(val > mx * mx) {
					res = mid;
					R = mid - 1;
				}
				else {
					L = mid + 1;
				}
			}
			if(res != - 1) {
				sum ++;
				a[++tot] = {res, m};
			}
		}
		if(ax[i] < 0) {
			int p = gf(i);
			if(p != - 1) {
				int L = p, R = m, res = - 1;
				while(L <= R) {
					int mid = L + R >> 1;
					ll val = gv2(i, mid);
					if(val > mx * mx) {
						res = mid;
						L = mid + 1;
					}
					else {
						R = mid - 1;
					}
				}
				if(res != - 1) {
					sum ++;
					a[++tot] = {p, res};
				}
			}
		}
	}
	sort(a + 1, a + tot + 1);
	int R = - 1;
	FOR(i, 1, tot) if(R < a[i].l) {
		ans ++;
		chmax(R, a[i].r);
	}
	cout << sum << " " << m - ans << endl;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}
