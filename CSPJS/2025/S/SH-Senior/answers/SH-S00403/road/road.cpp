#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e4 + 9, M = 2e6 + 9, K = 19;
#define re(i, n) for(ll i = 1; i <= n; i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
ll n, m, k;
struct Dat {
	ll u, v, w;
	bool operator < (const Dat &b) const {
		return w < b.w;
	}
} d[M], e[M]; ll cnt;
ll to[N], siz[N];
inline ll Find(ll u) { return u == to[u] ? u : to[u] = Find(to[u]); }
inline bool Union(ll u, ll v) {
	ll uu = Find(u), vv = Find(v);
	if(uu == vv) return 0;
	if(siz[uu] < siz[vv]) swap(uu, vv); 
	to[vv] = uu;
	siz[uu] += siz[vv];
	return 1;
}
ll c[K], a[K][N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m>>k;
	re(i, m) {
		ll u, v, w;
		cin>>u>>v>>w;
		d[i] = (Dat) {u, v, w};
	}
	re(i, k) {
		cin>>c[i];
		re(j, n) {
			cin>>a[i][j];
		}
	}
	ll ans = 1e17; 
	for(int b = 0; b < (1 << k); b++) {
		ll sum = 0;
		re(i, k) sum += (b >> (i - 1) & 1) * c[i];
		if(sum >= ans) continue;
		re(i, n) {
			to[i] = i;
			siz[i] = 1;
		}
		cnt = m;
		re(i, m) e[i] = d[i];
		ll comp = n;
		re(i, k) {
			if((b >> (i - 1) & 1) == 0) continue;
			comp++;
			re(j, n) {
				e[++cnt] = {n + i, j, a[i][j]};
			}
		}
		sort(e + 1, e + cnt + 1);
		re(i, cnt) {
			ll u = e[i].u, v = e[i].v, w = e[i].w;
			bool suc = Union(u, v);
			comp -= suc;
			sum += suc * w;
			if(sum >= ans) break; 
			if(comp == 1) break;
		}
		ans = min(ans, sum);
	} cout<<ans<<endl;
	return 0;
}

