#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
struct qwqw {
	int u, v, w;
} qwq[1150005];
int fir[120005][2];
bool cmp(qwqw x, qwqw y) {
	return x.w < y.w;
}
int hlcnt, fa[1000005];
int findfa(int u) {
	return fa[u] == u ? u : fa[u] = findfa(fa[u]);
}
int d[15];
void refa() {
	for(int i = 1; i <= n + k; ++i) {
		fa[i] = i;
	}
}
int add[110005], twt[110005];
void mergefir(int l, int r, int ll, int rr) {
	int i = l, j = ll, cnt = 0;
	for( ; j <= rr; ++j) {
        while(i <= r && qwq[fir[i][1]].w <= qwq[fir[j][1]].w) add[i] = cnt, ++i;
		twt[++cnt] = i;
	}
	while(i <= r && qwq[fir[i][1]].w > qwq[fir[j][1]].w) add[i] = cnt, ++i;
	for(int i = r; i >= l; --i) {
		fir[i + add[i]][1] = fir[i][1];
	}
	for(int i = ll; i <= rr; ++i) {
		fir[twt[i - ll + 1] + i - ll][1] = fir[i][1];
	}
}
int ans = 1000000000000000000;
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		cin >> qwq[i].u >> qwq[i].v >> qwq[i].w;
	}
	for(int i = 1; i <= k; ++i) {
		cin >> d[i];
		for(int j = 1; j <= n; ++j) {
			cin >> qwq[1000000 + 10000 * (i - 1) + j].w;
			qwq[1000000 + 10000 * (i - 1) + j].u = i + n;
			qwq[1000000 + 10000 * (i - 1) + j].v = j;
		}
		sort(qwq + 1000000 + 10000 * (i - 1) + 1, qwq + 1000000 + 10000 * (i - 1) + n + 1, cmp);
	}
	sort(qwq + 1, qwq + m + 1, cmp);
	refa();
	int tot = 0;
	for(int i = 1; i <= m; ++i) {
		int fau = findfa(qwq[i].u), fav = findfa(qwq[i].v);
		if(fau == fav) {
			continue;
		}
		fir[++hlcnt][0] = i;
		fa[fau] = fav;
		tot += qwq[i].w;
		if(hlcnt == n - 1) break;
	}
	ans = min(ans, tot);
	for(int i = 1; i < (1 << k); ++i) {
        int cntt = 0;
		for(int j = 1; j <= n - 1; ++j) fir[j][1] = fir[j][0];
		int cnt = n - 1, tot = 0;
		for(int j = 1; j <= k; ++j) {
			if(i & (1 << (j - 1))) {
			    tot += d[j]; ++cntt;
				for(int t = 1; t <= n; ++t) {
					fir[110000 + t][1] = 1000000 + 10000 * (j - 1) + t;
				}
				mergefir(1, cnt, 110001, 110000 + n);
				cnt += n;
			}
		}
		refa();
		for(int j = 1; j <= cnt; ++j) {
			int fau = findfa(qwq[fir[j][1]].u), fav = findfa(qwq[fir[j][1]].v);
			if(fau == fav) {
				continue;
			}
			fa[fau] = fav;
			tot += qwq[fir[j][1]].w;
			if(hlcnt == n + cntt - 1) break;
		}
		ans = min(ans, tot);
	}
	cout << ans << endl;
	return 0;
}
