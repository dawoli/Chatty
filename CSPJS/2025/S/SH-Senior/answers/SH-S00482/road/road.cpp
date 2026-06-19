#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,u,v,w,c,a,g[10010][10010],ans,vst[10010];
void build(ll u,ll v,ll w) {
	g[u][v]=max(g[u][v],w);
	g[v][u]=max(g[v][u],w);
}
bool check() {
	for (ll i=1;i<=n;i++) {
		if (vst[i]==0) return 0;
	}
	return 1;
}
void solve() {
	ll u=1;
	vst[1]=1;
	ll cur=0;
	while (1) {
		ll curans=0x3f3f3f3f;
		for (ll i=1;i<=n;i++) {
			if (g[u][i]<curans&&i!=u) curans=g[u][i],cur=i; 
		}
		cout<<cur;
		vst[cur]=1;
		vst[u]=1;
		u=cur;
		ans+=curans;
		if (check()) {
			cout<<ans<<endl;
			return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (ll i=1;i<=m;i++) {
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for (ll i=1;i<=k;i++) {
		cin>>c;
		for (ll j=1;j<=n;j++) {
			cin>>a;
			g[c][j]=a;
			g[j][c]=a;
		}
	}
	solve();
	return 0;
}
