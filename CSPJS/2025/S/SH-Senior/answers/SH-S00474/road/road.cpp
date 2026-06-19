#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10,M=1e6+10,K=20;
struct node {
	ll u,v,w;
} e[M+K*N];
ll n,m,k,ans,f[N+K];
bool cmp(const node &x,const node &y) {
	return x.w<y.w;
}
ll find(ll x) {
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1; i<=m; ++i) cin>>e[i].u>>e[i].v>>e[i].w;
	for(ll i=1,a; i<=k; ++i) {
		cin>>a;
		for(ll j=1; j<=n; ++j) cin>>a,e[++m].u=n+i,e[m].v=j,e[m].w=a;
	}
	sort(e+1,e+m+1,cmp);
	for(ll i=1; i<=n+k; ++i) f[i]=i;
	for(ll i=1; i<=m; ++i) {
		ll x=find(e[i].u),y=find(e[i].v);
		if(x!=y) ans+=e[i].w,f[x]=y;
	}
	cout<<ans;
	return 0;
}
