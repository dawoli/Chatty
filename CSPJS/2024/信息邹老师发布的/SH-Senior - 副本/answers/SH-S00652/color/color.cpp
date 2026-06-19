#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

namespace August_Light {
	void cmax(ll &x, ll y) {
		x = max(x, y);
	}
	ll n;
	ll a[MAXN];
	int v;
	
	namespace BF {
		void Main() {
			int tot = (1 << n) - 1;
			ll ans = 0;
			rep(u, 0, tot) {
				ll res = 0;
				rep(i, 1, n) {
					int t = (u >> (i-1) & 1);
					per(j, i-1, 1) {
						int p = (u >> (j-1) & 1);
						if (t == p) {
							if (a[i] == a[j])
								res += a[i];
							break;
						}
					}
				}
				ans = max(ans, res);
			}
			cout << ans << '\n';
		}
	}
	
	/*
	namespace Sub1 {
		const int maxn = 2e3 + 5;
		const int maxv = 2e3 + 5;
		ll f[maxn][maxv];
		ll s[maxn];
		int lst[maxv];
		int v;
		void clear() {
			rep(i, 0, n)
				rep(j, 0, v)
					f[i][j] = 0;
			rep(i, 2, n)
				s[i] = 0;
			rep(i, 0, v)
				lst[i] = 0;
		}
		ll h(ll l, ll r) {
			if (l > r)
				return 0;
			return s[r] - s[l];
		}
		void Main() {
			v = 0;
			rep(i, 1, n)
				v = max(v, (int)a[i]);
			rep(i, 2, n)
				s[i] = s[i-1] + (a[i] == a[i-1]) * a[i];
			rep(i, 1, n) {
				rep(j, 0, v) {
					if (lst[j]) {
						rep(k, lst[j], i-1)
							cmax(f[i][j], f[k][a[k+1]] + h(k+1, i) + j * (k == lst[j]));
					} else {
						rep(k, 0, i-1)
							cmax(f[i][j], f[k][a[k+1]] + h(k+1, i));
					}
						
					//if (j <= 10)
					//	cerr << f[i][j] << " \n"[j == 10];
				}
				lst[a[i]] = i;
			}
			cout << f[n][0] << '\n';
			clear();
		}
	}
	*/
	
	namespace Sub2 {
		const int maxn = 2e3 + 5;
		const int maxv = 2e3 + 5;
		ll f[maxn][maxv];
		ll s[maxn];
		ll g[maxn];
		int lst[maxv];
		bool valid() {
			return n <= 2e3 && v <= 2e3;
		}
		void clear() {
			rep(i, 0, n)
				rep(j, 0, v)
					f[i][j] = 0;
			rep(i, 0, n)
				s[i] = 0, g[i] = 0;
			rep(i, 0, v)
				lst[i] = 0;
		}
		void Main() {
			rep(i, 2, n)
				s[i] = s[i-1] + (a[i] == a[i-1]) * a[i];

			rep(i, 1, n) {
				rep(j, 0, v) {
					g[i] = max(g[i-1], f[i-1][a[i]] - s[i]);
					if (lst[j]) {
						int t = lst[j];
						cmax(f[i][j], max(g[i] + s[i], f[t][a[t+1]] - s[t+1] + s[i] + j));	
					} else {
						cmax(f[i][j], g[i] + s[i]);
					}
				}
				lst[a[i]] = i;
			}
			cout << f[n][0] << '\n';
			clear();
		}
	}
	
	namespace Sub3 {
		const int maxn = 2e5 + 5;
		const int maxv = 10 + 5;
		ll f[maxn][maxv];
		ll s[maxn];
		ll g[maxn];
		int lst[maxv];
		bool valid() {
			return n <= 2e5 && v <= 10;
		}
		void clear() {
			rep(i, 0, n)
				rep(j, 0, v)
					f[i][j] = 0;
			rep(i, 0, n)
				s[i] = 0, g[i] = 0;
			rep(i, 0, v)
				lst[i] = 0;
		}
		void Main() {
			rep(i, 2, n)
				s[i] = s[i-1] + (a[i] == a[i-1]) * a[i];

			rep(i, 1, n) {
				rep(j, 0, v) {
					g[i] = max(g[i-1], f[i-1][a[i]] - s[i]);
					if (lst[j]) {
						int t = lst[j];
						cmax(f[i][j], max(g[i] + s[i], f[t][a[t+1]] - s[t+1] + s[i] + j));	
					} else {
						cmax(f[i][j], g[i] + s[i]);
					}
				}
				lst[a[i]] = i;
			}
			cout << f[n][0] << '\n';
			clear();
		}
	}
	
	void Main() {
		cin >> n;
		rep(i, 1, n)
			cin >> a[i];
			
		v = 0;
		rep(i, 1, n)
			v = max(v, (int)a[i]);
		
		if (Sub2::valid())
			Sub2::Main();
		else if (n <= 15)
			BF::Main();
		else
			cout << -1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		August_Light::Main();
	}
	return 0;
}
