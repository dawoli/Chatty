#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = (l); i <= (r); ++i)
#define ROF(i, r, l) for (int i = (r); i >= (l); --i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
#define FI first
#define SE second
#define SZ(v) (int)((v).size())
#define allc(v) (v).begin(), (v).end()
#define popc(x) __builtin_popcount((x))
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
template <typename A, typename B>
void chkmax(A &x, B y) {
	x = (x > y) ? x : y;
}
template <typename A, typename B>
void chkmin(A &x, B y) {
	x = (x < y) ? x : y;
}
bool Meb;
namespace lyl {
	const int N = 5e2 + 5;
	const int mod = 998244353;
	int adds(int x, int y) { return ((x + y) >= mod) ? (x + y - mod) : (x + y); }
	void add(int &x, int y) { x = (x + y >= mod) ? (x + y - mod) : (x + y); }
	int decs(int x, int y) { return (x >= y) ? (x - y) : (x - y + mod); }
	void dec(int &x, int y) { x = (x >= y) ? (x - y) : (x - y + mod); }
	int muls(int x, int y) { return 1ll * x * y % mod; }
	void mul(int &x, int y) { x = 1ll * x * y % mod; }
	int qpow(int x, int y) {
		int res = 1;
		while (y) {
			if (y & 1) res = muls(res, x);
			y >>= 1;
			mul(x, x);
		}
		return res;
	}
	int divs(int x, int y) { return muls(x, qpow(y, mod - 2)); }
	void div(int &x, int y) { x = muls(x, qpow(y, mod - 2)); }
	int n, m, c[N], cnt[N], C[N][N], s[N], f[2][N][N], sum[N], fac[N], inv[N], A[N][N], val[N];
	string t;
	void solve() {
		cin >> n >> m >> t;
		t = " " + t;
		FOR (i, 1, n) s[i] = t[i] == '1';
		FOR (i, 1, n) {
			cin >> c[i];
			++cnt[c[i]]; 
		}
		sum[0] = cnt[0];
		FOR (i, 1, n) sum[i] = cnt[i] + sum[i - 1];
		fac[0] = 1;
		FOR (i, 1, n) fac[i] = muls(fac[i - 1], i);
		inv[n] = qpow(fac[n], mod - 2);
		ROF (i, n, 1) inv[i - 1] = muls(inv[i], i);
		C[0][0] = 1;
		FOR (i, 1, n) {
			C[i][0] = 1;
			FOR (j, 1, i) {
				C[i][j] = adds(C[i - 1][j - 1], C[i - 1][j]);
			}
		}
		A[0][0] = 1;
		FOR (i, 1, n) {
			FOR (j, 0, i) {
				A[i][j] = muls(fac[i], inv[i - j]);
			}
		}
		f[0][0][0] = 1;
		FOR (i, 0, n - 1) {
			int p = i & 1, q = i & 1 ^ 1;
			FOR (j, 0, i + 1) {
				FOR (k, 0, i + 1) {
					f[q][j][k] = 0;
				}
			}
			FOR (j, 0, i) {
				FOR (k, 0, i) {
					if (!f[p][j][k]) continue;
					int lim = min(k, cnt[j + 1]);
					FOR (x, 0, lim) val[x] = muls(muls(C[k][x], A[cnt[j + 1]][x]), f[p][j][k]);
					if (s[i + 1] == 1) {
						add(f[q][j][k + 1], f[p][j][k]);
						if (sum[j] <= i - k) continue;
						FOR (x, 0, lim) {
							int v = val[x];
							add(f[q][j + 1][k - x], muls(val[x], decs(sum[j], i - k)));
						}
					} else {
						int v = decs(sum[j], i - k);
						if (sum[j] > i - k) {
							FOR (x, 0, lim) {
								add(f[q][j + 1][k - x], muls(v, val[x]));
							} 
						}
						v = muls(f[p][j][k], cnt[j + 1]);
						FOR (x, 0, min(k, cnt[j + 1] - 1)) {
							add(f[q][j + 1][k - x], muls(v, muls(C[k][x], A[cnt[j + 1] - 1][x])));
						} 
						FOR (x, 0, lim) {
							add(f[q][j + 1][k - x + 1], val[x]);
						}  
					}
				}
			}
		}
		int ans = 0;
		FOR (j, 0, n - m) {
			FOR (k, n - sum[j], n - sum[j]) {
				add(ans, muls(f[n & 1][j][k], A[n - sum[j]][k]));
			}
		}
		cout << ans << '\n';
	}	
};
bool Mbe;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	lyl::solve();
//	 cerr << "Space: " << abs(&Meb - &Mbe) / 1024.0 / 1024.0 << "MB\n";
	// cerr << "Time: << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
 	return 0;
}
/*
3 1
011
1 2 2
*/
