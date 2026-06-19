#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10025
#define M 1100255
#define C 15
ll n, m, k, c[C], val[C], a[C][N], nE, use[C], nUse, nV, sz[N], cnt, ans;
struct Edge{
	ll u, v, w;
}e[M], e1[M];
bool cmp(const Edge &A, const Edge &B){
	return A.w < B.w;
}
ll fa[N];
ll findfa(ll u){
	if(fa[u] == u) return u;
	return fa[u] = findfa(fa[u]);
}
void unite(ll u, ll v){
	if(findfa(u) == findfa(v)) return ;
	if(sz[findfa(u)] > sz[findfa(v)]){
		fa[findfa(v)] = findfa(u);
		sz[findfa(u)] += sz[findfa(v)];
	}else{
		fa[findfa(u)] = findfa(v);
		sz[findfa(v)] += sz[findfa(u)];
	}
}
ll solveBF(){
	for(ll i = 1; i <= nE; i++){
		e1[i] = e[i];
	}
	nV = n + nUse;
	nUse = 0;
	for(ll i = 1; i <= k; i++){
		if(!use[i]) continue;
		nUse++;
		for(ll j = 1; j <= n; j++){
			e1[++nE].u = n + nUse;
			e1[nE].v = j;
			e1[nE].w = a[i][j];
		}
	}
	cnt = nV;
	for(ll i = 1; i <= nV; i++){
		fa[i] = i;
		sz[i] = 1;
	}
	ll res = 0;
	sort(e1+1, e1+nE+1, cmp);
	for(ll i = 1; i <= nE; i++){
		ll u = e1[i].u, v = e1[i].v, w = e1[i].w;
		if(findfa(u) == findfa(v)) continue;
		unite(u, v);
		res += w;
		cnt--;
		if(cnt == 1) break;
	}
	for(ll i = 1; i <= k; i++){
		if(!use[i]) continue;
		for(ll j = 1; j <= n; j++){
			nE--;
		}
	}
	return res;
}
void dfsBF(ll x, ll sum, ll sumval){
	if(x == k + 1){
		ans = min(ans, sum + solveBF());
		return ;
	}
	dfsBF(x + 1, sum, sumval);
	if(m > 100000){
		if(sumval + val[x] < ans / 4){
			use[x] = 1;
			nUse++;
			dfsBF(x + 1, sum + c[x], sumval + val[x]);
			use[x] = 0;
			nUse--;
		}
	}else{
		if(sumval + val[x] < ans){
			use[x] = 1;
			nUse++;
			dfsBF(x + 1, sum + c[x], sumval + val[x]);
			use[x] = 0;
			nUse--;
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(ll i = 1; i <= m; i++){
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		e[++nE].u = u;
		e[nE].v = v;
		e[nE].w = w;
	}
	for(ll i = 1; i <= k; i++) {
		cin >> c[i];
		ll mn1 = 1e18, mn2 = 1e18;
		for(ll j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] < mn1){
				mn2 = mn1;
				mn1 = a[i][j];
			}else if(a[i][j] < mn2){
				mn2 = a[i][j];
			}
		}
		val[i] = c[i] + mn1 + mn2;
	}
	ans = 1e18;
	dfsBF(1, 0, 0);
	cout << ans << endl;
	return 0;
}
