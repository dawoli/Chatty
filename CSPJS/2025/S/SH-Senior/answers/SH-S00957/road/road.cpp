#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool M1;
const int N = 1e4 + 10;
const int K = 15;
const int MR = (1 << 10) + 10;
const int M = 1e6 + 10;
const ll Linf = 1e18;
int n, m, k, a[K][N], c[K], fa[N + K], cnt[MR];
ll ans;
struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int _u, int _v, int _w){
		u = _u, v = _v, w = _w;
	}
	bool operator < (const Edge& b) const{
		return w < b.w;
	}
}e[M], vec[MR][N + K], tmp[N * 2 + K];

void init(){
	for (int i = 1; i <= n + k; i++){
		fa[i] = i;
	}
}
int Find(int x){
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

bool M2;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cerr << 1.0 * fabs(&M1 - &M2) / 1024 / 1024 << " MB\n" ;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	ll mst = 0;
	sort(e + 1, e + m + 1), init();
	for (int i = 1, u, v, w; i <= m; i++){
		u = e[i].u;
		v = e[i].v;
		w = e[i].w;
		if (Find(u) != Find(v)){
			fa[Find(u)] = Find(v), mst += w;
			vec[0][++ cnt[0]] = Edge(u, v, w);
		}
	}
	ans = mst;
	for (int S = 1; S < (1 << k); S++){
		ll cur = 0;
		for (int i = 1; i <= k; i++)
			if (S >> (i - 1) & 1){
				cur += c[i];
			}
		int lb = S & (- S);
		int p = __lg(lb) + 1, lst = S - lb;
		for (int i = 1; i <= cnt[lst]; i++){
			tmp[i] = vec[lst][i];
		}
		int tot = cnt[lst];
		for (int i = 1; i <= n; i++){
			tmp[++ tot] = Edge(p + n, i, a[p][i]);
		}
		sort(tmp + 1, tmp + tot + 1), init();
		for (int i = 1, u, v, w; i <= tot; i++){
			u = tmp[i].u;
			v = tmp[i].v;
			w = tmp[i].w;
			if (Find(u) != Find(v)){
				fa[Find(u)] = Find(v), cur += w;
				vec[S][++ cnt[S]] = Edge(u, v, w);
			}
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
