#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=2500009;
struct Edge{
	ll u,v,w,t;
}e[M],g[M],tmp[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w||x.w==y.w&&x.u<y.u||x.u==y.u&&x.w==y.w&&x.v<y.v;
}
ll n,m,k;
const ll K=19,N=15009;
ll a[K][N],f[N],b[K],c[K],nV,nE,cnt[M],t[K];
ll root(ll u){
	return (f[u]==u?u:f[u]=root(f[u]));
}
ll kruskal(){
	ll k=0,ans=0;
	for(int i=1;i<=nE;i++){
		ll u=root(e[i].u),v=root(e[i].v);
		if(u==v) continue;
		f[u]=v;
		ans+=e[i].w;
		k++;
		if(k==nV-1) return ans;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w,tmp[i].u=u,tmp[i].v=v,tmp[i].w=w;
	}
	for(ll j=1;j<=k;j++)
		for(ll i=1;i<=n+1;i++){
			if(i==1) cin>>c[j];
			else cin>>a[j][i-1];
		}
	nE=m;nV=n;
	sort(e+1,e+1+m,cmp);
	for(ll i=1;i<=nV;i++) f[i]=i;
	ll x=kruskal();
	if(k==0){
		cout<<x<<endl;
		return 0;
	}
	ll ans=x,nE1=m,nV1=n;
	for(ll j=1;j<=m;j++) g[j]=tmp[j];
	for(ll j=1;j<=k;j++){
		nV1++;
		for(ll l=1;l<=n;l++){
			g[++nE1].u=nV1;
			g[nE1].t=n+j;
			g[nE1].v=l;
			g[nE1].w=a[j][l];
		}
	}
	sort(g+1,g+1+nE1,cmp);
	for(ll i=1;i<(1<<k);i++){
		nE=0;nV=n;
		for(ll j=1;j<=k;j++) b[j]=(i>>(k-j))&1;
		ll y=0;
		for(ll j=1;j<=k;j++){
			if(!b[j]) continue;
			nV++;
			b[j]=nV;
			y+=c[j];
		}
		for(ll l=1;l<=nE1;l++)
			if(b[g[l].t-n]&&!cnt[l]) e[++nE]=(Edge){b[g[l].t-n],g[l].v,g[l].w,0},cnt[l]=1;
			else if(!g[l].t&&!cnt[l]) e[++nE]=(Edge){g[l].u,g[l].v,g[l].w,0},cnt[l]=1;
		for(ll j=1;j<=nV;j++) f[j]=j;
		y+=kruskal();
		ans=min(ans,y);
		for(ll l=1;l<=nE1;l++) cnt[l]=0;
	}
	cout<<ans<<endl;
	return 0;
}
