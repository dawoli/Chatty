#include <bits/stdc++.h> 


using namespace std;
using ll = long long;
int n, m, k;
// vector<pair<int,ll>> edges[300010];
struct SEdge {
	int u, v;
	ll w;
	bool operator<(const SEdge & rhs) const {
		return w < rhs.w;
	}
} edge[1020000], edgeR[1020000];

int c[110];
ll a[110][30010];

namespace DSU {
	int fa[300010];
	int sz = 0;
	int cnt=0;
	
	void init(int siz) {
		sz = siz;
		cnt = sz;
		for (int i=1;i<=sz;i++) fa[i] = i;
	}
	
	int Find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = Find(fa[x]);
	}
	
	bool Same(int x, int y) {
		return Find(x) == Find(y);
	}
	
	int TrySame(int x, int y) {
		if (Same(x, y)) return Find(x);
		return 0;
	}
	
	bool Merge(int x, int y) { 
		if (Same(x, y)) return false;
		fa[Find(y)] = Find(x);
		cnt--;
		return true;
	}
	
	
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1;i<=m;i++) {
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		edge[i].u = u;
		edge[i].v = v;
		edge[i].w = w;
	}
	for (int i=1;i<=k;i++) {
		scanf("%d", &c[i]);
		for (int j=1;j<=n;j++) scanf("%lld", &a[i][j]);
	}
	
	DSU::init(n);
	sort(edge+1, edge+m+1);
	memcpy(edgeR, edge, sizeof(edge));
	
	ll ans = 0;
	ll succ = 0;
	
	for (int i=1;i<=m;i++) {
		if (DSU::cnt <= 1) break;
		if (DSU::Merge(edge[i].u, edge[i].v)) {succ++;ans += edge[i].w;}//cerr<<ans-edge[i].w<<"+"<<edge[i].w<<"->"<<ans<<endl;}
	}
	// if (DSU::cnt > 1) printf("IMPOSSIBLE\n");
	
	// printf("%lld\n", ans);
	
	for (int mask = 1; mask < (1<<k); mask++) {
		memcpy(edge, edgeR, sizeof(edgeR));
		int ecnt = m, rri = 0;
		int oooo = __builtin_popcount(mask);
		ll base = 0;
		for (int i=1;i<=k;i++) {
			if (!(mask & (1<<(i-1)))) continue;
			++rri;
			base += c[i];
			for (int j=1;j<=n;j++) edge[++ecnt] = {n+rri, j, a[i][j]};
		}
//		for (int i=1;i<=ecnt;i++) {
//			// cerr<<edge[i].u<<"<=>"<<edge[i].v<<",cost="<<edge[i].w<<endl;
//		}
		DSU::init(n+oooo);
		sort(edge+1, edge+ecnt+1);
		ll aaans = 0;
		for (int i=1;i<=ecnt;i++) {
			if (DSU::cnt <= 1) break;
			if (DSU::Merge(edge[i].u, edge[i].v)) {succ++;aaans += edge[i].w;}//cerr<<edge[i].u<<"<->"<<edge[i].v<<"   "<<aaans-edge[i].w<<"+"<<edge[i].w<<"->"<<aaans<<endl;}
		}
		int zcnt = 0;
		for (int i=1;i<=n+oooo;i++) if (i == DSU::fa[i]) zcnt++;
		if (zcnt>=2) {fprintf(stderr, "Error: %lld\n", aaans+base);
		for (int i=1;i<=n+oooo;i++) if (i == DSU::fa[i]) cerr<<i<<" ";
		cerr<<endl;
		}
		ans = min(ans, aaans+base);
		
	}
	printf("%lld\n", ans);
	
	
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int T = 1;
	// scanf("%d", &T);
	while (T--) solve();
	return 0;
}
