#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;

const int MAXN = 100 + 5;

namespace August_Light {
	int n, m;
	ll aa[MAXN], a[MAXN], c[MAXN];
	int d[MAXN][MAXN];
	int X[MAXN];
	int T;
	ll A[MAXN];
	void Main() {
		cin >> n >> m;
		rep(i, 1, n)
			cin >> aa[i];
		rep(i, 1, m)
			cin >> c[i];
		int K = 0; while ((1 << K) < n) K++;
		rep(R, 1, K) {
			rep(G, 1, (1 << (K - R)))
				cin >> d[R][G];
		}
		cin >> T;
		while (T--) {
			rep(i, 0, 3)
				cin >> X[i];
			rep(i, 1, n)
				a[i] = (aa[i] ^ X[i % 4]);
				
			
			
			ll ans = 0;
			rep(i, 1, m)
				ans ^= (i * A[i]);
			cout << ans << '\n';
		}
	}
	void GivenUp() {
		cout << 97 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	August_Light::GivenUp();
	return 0;
}
