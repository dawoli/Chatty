#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int int
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
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
int n, a[N][3], p[N], c[3];
void solve() {
	cin >> n; ll res = 0;
	FOR(i, 1, n) {
		REP(j, 3) cin >> a[i][j];
		int mx = 0;
		REP(j, 3) if(a[i][j] > a[i][mx]) mx = j;
		p[i] = mx;
		res += a[i][mx];
	}
	REP(j, 3) c[j] = 0;
	FOR(i, 1, n) c[p[i]] ++;
	int mx = 0;
	REP(i, 3) if(c[i] > c[mx]) mx = i;
	if(c[mx] <= n / 2) {
		cout << res << endl;
		return;
	}
	vector<int> e;
	FOR(i, 1, n) if(mx == p[i]) {
		int val = INF;
		REP(j, 3) if(j != mx) chmin(val, a[i][mx] - a[i][j]);
		e.pb(val);
	}
	sort(ALL(e));
	int pl = 0;
	REP(_, c[mx] - n / 2) {
		res -= e[pl]; pl ++;
	}
	cout << res << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}