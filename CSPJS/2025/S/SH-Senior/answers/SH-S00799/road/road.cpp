#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+9,M=1e6+9;
ll n,m,k,cntE,id[N],c[20],a[20][N];
struct Edge{
	ll u,v,w;
}e[M],t[M],g[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
bool cmpc(ll a,ll b){
	return c[a]<c[b];
}
ll root(ll x){
	if(id[x]==x) return x;
	return id[x]=root(id[x]);
}
ll idd[20];//plz 80
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	ll ans=0;
	sort(e+1,e+m+1,cmp);
	for(ll i=1;i<=n;i++) id[i]=i;
	for(ll i=1;i<=m;i++){
		ll ru=root(e[i].u),rv=root(e[i].v);
		if(ru==rv) continue;
		t[++cntE]=e[i];
		ans+=e[i].w;
		id[ru]=rv;
	}
	m=cntE;
	for(ll i=1;i<=cntE;i++) e[i]=t[i];
	if(k==0){
		printf("%lld\n",ans);
		return 0;
	}
	ll sumc=0;
	for(ll i=1;i<=k;i++) idd[i]=i;
	sort(idd+1,idd+k+1,cmpc);
	for(ll ii=1;ii<=k;ii++){
		ll i=idd[ii];
		for(ll j=1;j<=m;j++) t[j]=e[j];
		for(ll j=1;j<=n;j++) t[m+j]=(Edge){n+i,j,a[i][j]};
		cntE=n+m;
		sort(t+1,t+cntE+1,cmp);
		for(ll j=1;j<=n+k;j++) id[j]=j;
		ll res=0,cntn=0;
		for(ll j=1;j<=cntE;j++)if(cntn<m+1){
			ll ru=root(t[j].u),rv=root(t[j].v);
			if(ru==rv) continue;
			g[++cntn]=t[j];
			res+=t[j].w;
			id[ru]=rv;
		}
		if(res+sumc+c[i]<ans){
			sumc+=c[i];
			ans=res+sumc;
			m=cntn;
			for(ll j=1;j<=m;j++) e[j]=g[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
