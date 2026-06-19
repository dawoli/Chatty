#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct E{
	ll u,v,w;
};
E f[2000010],g[2000010];
ll c[20],t[20][10010];
ll id[10010];
ll find(ll x){
	if(id[x]!=x)	return id[x]=find(id[x]);
	else			return x;
}
bool cmp(E a,E b){
	return a.w<b.w;
} 
ll mst(){
	for(ll i=1;i<=n;++i)
		id[i]=i;
	for(ll i=1;i<=m;++i)
		g[i].u=f[i].u,g[i].v=f[i].v,g[i].w=f[i].w;
	sort(g+1,g+m+1,cmp);
	ll cnt=1,sm=0;
	for(ll i=1;i<=m&&cnt<n;++i){
		ll p=find(g[i].u),q=find(g[i].v);
		if(p!=q){
			id[p]=q;
			sm+=g[i].w;
			cnt++;
		}
	}
	return sm;
}
bool vis[20];
ll T[20];
ll ans=0x3f3f3f3f3f3f3f3f;
void check(){
	ll mm=m,cst=0;
	for(ll i=1;i<=k;++i)
		if(vis[i]){
			for(ll j=1;j<=n;++j)
				if(j!=T[i]){				
					f[++m].u=T[i],f[m].v=j,f[m].w=t[i][T[i]]+t[i][j];
				}
			cst+=c[i];
		}
	ans=min(ans,cst+mst());
	m=mm;
}
void dfs(ll dep){
	if(dep==k+1)	check();
	else{
		dfs(dep+1);
		vis[dep]=true;
		dfs(dep+1);
		vis[dep]=false;
	}
}
ll dt(){
	ll cst=0;
	for(ll i=1;i<=k;++i){
		for(ll j=1;j<=n;++j)
			if(j!=T[i]){				
				f[++m].u=T[i],f[m].v=j,f[m].w=t[i][T[i]]+t[i][j];
			}
		cst+=c[i];
	}
	return cst+mst();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;++i)
		scanf("%lld%lld%lld",&f[i].u,&f[i].v,&f[i].w);
	ll s=0;
	for(ll i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		s+=c[i];
		for(ll j=1;j<=n;++j)
			scanf("%lld",&t[i][j]);
		ll minn=0x3f3f3f3f,id=0;
		for(ll j=1;j<=n;++j)
			if(minn>t[i][j]){
				minn=t[i][j];
				id=j;
			}
		T[i]=id;
	}
	if(k==0)	printf("%lld",mst());
	else if(s==0)	printf("%lld",dt());
	else		dfs(1),cout<<ans<<endl;
}
