#include<bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
const int N = 1e4+100, M = 2e6+10, K = 20;
int n, m, k;
int a[N][K];
int c[K];
struct g{
	int u, v, w;
}e[M];
int f[N];
int ans, cnt;
bool vis[N];
bool cmp(g x, g y){
	return x.w < y.w;	
}
int getroot(int u){
	return f[u] == u ? u : (f[u]=getroot(f[u]));
}
void comm(int u, int v, int w){
	if(u>n && !vis[u]){
		return;
	}
	int fu = getroot(u), fv = getroot(v);
	
	if(fu!=fv){
		if(u <= n && u && !vis[u]) cnt++;
		if(v <= n && v && !vis[v]) cnt++;
		f[fu] = fv;
		ans+=w;
		vis[u] = 1, vis[v] = 1; 
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	int tot = 0;
	for(int i=1; i<=m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		e[++tot].w = w, e[tot].u = u, e[tot].v = v;
	}
	for(int i=1; i<=k; ++i){
		cin >> c[i];
		e[++tot].w = c[i], e[tot].u = 0, e[tot].v = n+i;
		for(int j=1; j<=n; ++j){
			cin >> a[j][i];
			e[++tot].w = a[j][i], e[tot].u = n+i, e[tot].v = j;
		}
	}
	sort(e+1, e+tot+1, cmp);
	for(int i=1; i<=n+k; ++i) f[i] = i;
	for(int i=1; i<=tot; ++i){
		if(cnt>=n){
			cout << ans << endl;
			return 0;	
		}
		int u = e[i].u, v = e[i].v, w = e[i].w;
		comm(u, v, w); 
	}
	cout << ans << endl;
	return 0;	
}
