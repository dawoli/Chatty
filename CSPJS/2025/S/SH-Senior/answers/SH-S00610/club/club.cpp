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
	const int N = 1e5 + 5;
	int n, c[3], id[N];
	ll a[N][3], ans, val[N];
	void solve() {
		cin >> n;
		ans = 0;
		memset(c, 0, sizeof(c));
		FOR (i, 1, n) {
			FOR (j, 0, 2) {
				cin >> a[i][j];
			}
			ll mx = max(a[i][0], max(a[i][1], a[i][2]));
			ans += mx;
			ll smx = 0;
			FOR (j, 0, 2) {
				if (a[i][j] == mx) {
					++c[j];
					id[i] = j;
					break;
				}
			}
			FOR (j, 0, 2) {
				if (j != id[i]) chkmax(smx, a[i][j]);
			}
			val[i] = smx - mx;
		}
		FOR (j, 0, 2) {
			if (c[j] > n / 2) {
				vector<ll> v;
				FOR (i, 1, n) {
					if (id[i] == j) {
						v.PB(val[i]);
					}
				}
				sort(allc(v));
				while (c[j] > n / 2) {
					ans += v.back();
					v.pop_back();
					--c[j];
				}
			}
		}
		cout << ans << '\n';
		
	}	
};
bool Mbe;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		lyl::solve();
	}
	// cerr << "Space: " << abs(&Meb - &Mbe) / 1024.0 / 1024.0 << "MB\n";
	// cerr << "Time: << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
 	return 0;
}
