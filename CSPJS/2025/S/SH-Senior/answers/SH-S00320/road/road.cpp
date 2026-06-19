#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+5;
const int N=1e4+55;
bool ffff;
ll n,m,k,hd[N],ne=0,ne2=0,c[20],a[N][20],ans=1e18,fa[N];
struct edge{
	ll u,v,w;
	bool operator < (const edge &k) const{
		return k.w>w;
	}
}e[M],e2[M];
struct que{
	ll u,v,w;
}q[M];
bool tttt;
void addedge(ll u,ll v,ll w){
	e[++ne]={u,v,w};
}
void addedge2(ll u,ll v,ll w){
	e2[++ne2]={u,v,w};
}
ll find(ll u){
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
bool check(ll u,ll v){
	ll fu=find(u),fv=find(v);
	if(fu==fv) return 0;
	return 1;
}
void merge(ll u,ll v){
	ll fu=find(u),fv=find(v);
	if(fu<fv) fa[fv]=fu;
	else fa[fu]=fv;
	return;
}
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++){
		q[i].u=read(),q[i].v=read(),q[i].w=read();
		addedge(q[i].u,q[i].v,q[i].w);
	}
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1;j<=n;j++){
			a[j][i]=read();
		}
	}
	sort(e+1,e+ne+1);
	for(ll st=0;st<(1<<k);st++){
		ll sum=0,numx=0;ne2=0; 
		for(ll pos=1;pos<=k;pos++){
			if((st>>(pos-1))&1){
				sum+=c[pos]; numx++;
				for(ll i=1;i<=n;i++) addedge2(i,n+pos,a[i][pos]);
			}
		}
		for(ll i=1;i<=n+k;i++) fa[i]=i;
		sort(e2+1,e2+ne2+1);
		ll cnt=0,zz1=1,zz2=1;
		while(cnt<n+numx-1){
			if(e[zz1].w<e2[zz2].w||zz2>ne2){
				ll un=e[zz1].u,vn=e[zz1].v,wn=e[zz1].w;
				if(check(un,vn)){
					merge(un,vn); sum+=wn;cnt++;
				}
				zz1++;
			}
			else{
				ll un=e2[zz2].u,vn=e2[zz2].v,wn=e2[zz2].w;
				if(check(un,vn)){
					merge(un,vn); sum+=wn; cnt++;
				}
				zz2++;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
