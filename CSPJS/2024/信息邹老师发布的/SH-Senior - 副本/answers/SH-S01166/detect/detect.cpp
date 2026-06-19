#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;
const ll M = 1e5 + 10;
ll T, n, m, len, lmt;
// start_point, speed, jiasudu
ll d[N], v[N], a[N], p[M], diff[M];
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3ll) + (x << 1ll) + (ch & 15ll);
		ch = getchar();
	}
	return x * f;
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
//	scanf("%lld", &T);
	T = read();
	while (T--) {
		n = read(); m = read(); len = read(); lmt = read();
//		scanf("%lld %lld %lld %lld", &n, &m, &len, &lmt);
		for (int i = 1; i <= n; i ++) {
//			scanf("%lld %lld %lld", &d[i], &v[i], &a[i]);
			d[i] = read(); v[i] = read(); a[i] = read();
		}
		if (n > 20) {
			ll maxp = 0;
			for (int i = 1; i <= m; i ++) {
	//			scanf("%lld", &p[i]);
				p[i] = read();
				maxp = max(maxp, p[i]);
			}
			ll init_cnt = 0;
			for (int i = 1; i <= n; i ++) {
				if (maxp < d[i]) continue;
				if (v[i] * v[i] + 2 * a[i] * (maxp - d[i]) > lmt * lmt)
					init_cnt ++;
			}
			ll max_close = 0;
			if (init_cnt == 0)
				max_close = m;
			else max_close = m - 1;
			printf("%lld %lld\n", init_cnt, max_close);
		} else {
			for (int i = 1; i <= m; i ++)
				p[i] = read();
			ll init_cnt = 0;
			for (int i = 1; i <= n; i ++) {
				bool chaosu = false;
				for (int j = 1; j <= m; j ++) {
					if (p[j] < d[i]) continue;
					if (v[i] * v[i] + 2 * a[i] * (p[j] - d[i]) < 0)
						break;
					if (v[i] * v[i] + 2 * a[i] * (p[j] - d[i])
					> lmt * lmt) {
						chaosu = true;
						break;
					}
				}
				if (chaosu) init_cnt ++;
			}
			ll max_close = 0;
			for (ll i = 0; i < (1ll << m); i ++) {
				bool closed[25]; ll close_cnt = 0;
				for (ll j = 1; j <= m; j ++) closed[j] = 0;
				for (ll j = 0; j < m; j ++) {
					if (i & (1ll << j)) {
						closed[j+1] = true;
						close_cnt ++;
					}
				}
				ll after_cnt = 0;
				for (int x = 1; x <= n; x ++) {
					bool chaosu = false;
					for (int y = 1; y <= m; y ++) {
						if (p[y] < d[x] || closed[y]) continue;
						if (v[x] * v[x] + 2 * a[x] * (p[y] - d[x]) < 0)
							break;
						if (v[x] * v[x] + 2 * a[x] * (p[y] - d[x])
						> lmt * lmt) {
							chaosu = true;
						}
					}
					if (chaosu) after_cnt ++;
				}
				if (init_cnt == after_cnt)
					max_close = max(max_close, close_cnt);
			}
			printf("%lld %lld\n", init_cnt, max_close);						
		}
	}
	return 0;
}
