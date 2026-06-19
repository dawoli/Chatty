#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAXM = 7e6 + 5, MAXN = 1e4 + 5;
ll n, m, k, aans, fa[MAXN], a[14][MAXN], rnk[MAXN], siz[MAXN], c[15];
bool used[10][MAXN];
struct Edge{
	ll u, v, w, bel;
}ed[MAXM];
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
ll find(ll x){return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));}
void merge(ll x, ll y){
	x = find(x), y = find(y);
	if(rnk[x] > rnk[y])swap(x, y);
	fa[x] = y;
	if(rnk[x] == rnk[y])rnk[y]++;
	siz[y] += siz[x];
}
signed main(){
	cin.tie(0) -> sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)cin >> ed[i].u >> ed[i].v >> ed[i].w, ed[i].bel = 0;
	ll cur = m + 1;
	bool flag = true;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		if(c[i] != 0)flag = false;
		for(int j = 1; j <= n; j++)cin >> a[i][j];
		for(int j = 1; j < n; j++)
			for(int z = j + 1; z <= n; z++){
				cur++;
				ed[cur].u = z;
				ed[cur].v = j;
				ed[cur].w = a[i][z] + a[i][j];
				ed[cur].bel = i;
			}
	}
	sort(ed + 1, ed + cur + 1, cmp);
	aans = (ll)(0x3f3f3f3f3f3f3f3f);
	if(flag){
		ll ans = 0;
		for(int i = 1; i <= n; i++)rnk[i] = siz[i] = 1, fa[i] = i;
		for(int j = 1; j <= cur; j++){
			ll u = ed[j].u, v = ed[j].v, bel = ed[j].bel;
			if(find(u) != find(v)){
				merge(u, v);
				if(bel == 0)ans += ed[j].w;
				else{
					if(!used[bel][u])ans += a[bel][u];
					if(!used[bel][v])ans += a[bel][v];
					used[bel][u] = used[bel][v] = true;
				}
				if(max(siz[u], siz[v]) == n)break;
			}
		}
		aans = min(aans, ans);
	}
	if(!flag){
		for(int i = 0; i < (1 << k); i++){
			vector<pair<ll, ll> > e;
			ll ans = 0;
			for(int i = 1; i <= n; i++)rnk[i] = siz[i] = 1, fa[i] = i;
			for(int j = 1; j <= cur; j++){
				ll u = ed[j].u, v = ed[j].v, bel = ed[j].bel;
				if((bel == 0 || (i & (1 << (bel - 1)))) && find(u) != find(v)){
					// cout << u << ' ' << v << ' ' << bel << ' ' << ed[j].w << endl;
					merge(u, v);
					if(bel == 0)ans += ed[j].w;
					else{
						if(!used[bel][u])ans += a[bel][u], e.push_back(make_pair(bel, u));
						if(!used[bel][v])ans += a[bel][v], e.push_back(make_pair(bel, v));
						used[bel][u] = used[bel][v] = true;
					}
					if(max(siz[u], siz[v]) == n)break;
				}
			}
			// cout << endl;
			for(auto z : e)used[z.first][z.second] = false;
			for(int j = 1; j <= k; j++)if((1 << (j - 1) & i) != 0)ans += c[j];
			aans = min(aans, ans);
		}
	}
	cout << aans << endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/