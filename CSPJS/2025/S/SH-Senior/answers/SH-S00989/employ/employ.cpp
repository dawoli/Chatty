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
bool __ST__;
const int N = 105;
const int P = 998244353;
int add(int x, int y) { return x + y < P ? x + y : x + y - P; }
void Add(int & x, int y) { x = x + y < P ? x + y : x + y - P; }
int sub(int x, int y) { return x < y ? x - y + P : x - y; }
void Sub(int & x, int y) { x = x < y ? x - y + P : x - y; }
int mul(int x, int y) { return (1ll * x * y) % P; }
void Mul(int & x, int y) { x = (1ll * x * y) % P; }
int fp(int x, int y) {
	int res = 1;
	for(; y; y >>= 1) {
		if(y & 1) Mul(res, x);
		Mul(x, x);
	}
	return res;
}
int n, m, a[N], c[N], sc[N];
string s;
int fac[N], finv[N];
int dp[2][N][N][N];
namespace S1 {
	const int N = 18;
	int dp[1 << N][N + 1];
	void solve() {
		dp[0][0] = 1;
		int lim = 1 << n, U = lim - 1;
		FOR(S, 1, U) {
			int u = __builtin_popcount(S);
			if(s[u] == '0') {
				REP(i, n) if(S >> i & 1) {
					int T = S ^ (1 << i);
					FOR(j, 0, n) if(dp[T][j]) {
						Add(dp[S][j + 1], dp[T][j]);
					}
				}
			}
			else {
				REP(i, n) if(S >> i & 1) {
					int T = S ^ (1 << i);
					FOR(j, 0, n) if(dp[T][j]) {
						if(j >= a[i + 1]) Add(dp[S][j + 1], dp[T][j]);
						else Add(dp[S][j], dp[T][j]);
					}
				}
			}
		}
		int ans = 0;
		FOR(i, 0, n) {
			int k = n - i;
			if(k >= m) Add(ans, dp[U][i]);
		}
		cout << ans << endl;
	}
}
bool __ED__;
void init(int n) {
	fac[0] = 1;
	FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
	finv[n] = fp(fac[n], P - 2);
	ROF(i, n - 1, 0) finv[i] = mul(finv[i + 1], i + 1);
}
inline int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return mul(mul(fac[x], finv[y]), finv[x - y]);
}
void solve() {
	// cerr << abs(& __ST__ - & __ED__) / 1e6 << " MB" << endl;
	cin >> n >> m; init(n);
	cin >> s; s = ' ' + s;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) c[a[i]] ++;
	FOR(i, 1, n) sc[i] = sc[i - 1] + c[i];
	if(n <= 18) { S1 :: solve(); return; }
	int o = 0;
	dp[o][0][c[0]][0] = 1;
	FOR(i, 1, n) {
		o ^= 1;
		memset(dp[o], 0, sizeof dp[o]);
		if(s[i] == '0') {
			FOR(j, 0, n) FOR(l, 0, n) FOR(r, 0, n) if(dp[o ^ 1][j][l][r]) {
				int val = dp[o ^ 1][j][l][r];
				FOR(k, 0, min(r, c[j + 1])) {
					Add(dp[o][j + 1][l + c[j + 1] - k - 1][r - k], mul(mul(val, c[j + 1] - k), C(c[j + 1], k)));
					Add(dp[o][j + 1][l + c[j + 1] - k][r - k + 1], mul(val, C(c[j + 1], k)));
					Add(dp[o][j + 1][l + c[j + 1] - k - 1][r - k], mul(mul(val, l), C(c[j + 1], k)));
				}
			}
		}
		else {
			FOR(j, 0, n) FOR(l, 0, n) FOR(r, 0, n) if(dp[o ^ 1][j][l][r]) {
				int val = dp[o ^ 1][j][l][r];
				Add(dp[o][j][l][r + 1], val);
				if(l) {
					FOR(k, 0, min(r, c[j + 1])) {
						Add(dp[o][j + 1][l - 1 + c[j + 1] - k][r - k], mul(mul(val, l), mul(mul(C(r, k), fac[k]), C(c[j + 1], k))));
					}
				}
			}
		}
	}
	int ans = 0;
	FOR(i, 0, n) FOR(r, 0, n) if(n - i >= m)
		Add(ans, mul(dp[o][i][0][r], fac[r]));
	cout << ans << endl;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}