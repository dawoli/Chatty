#include<bits/stdc++.h>
#define N 10001
#define M 1000001
#define K 11
#define P 1024
#define V N+K
#define INF 1e18
using namespace std;
typedef long long ll;
ll n,m,k,c[K],a[K][N],id[V],nV,nE;
bool ok[K];
struct Edge{
	ll u,v,w;
	bool operator<(const Edge&ed)const{
		return w<ed.w;
	}
} ed[M+N*K];
ll find(ll u){
	if(id[u]==u) return u;
	return (id[u]=find(id[u]));
}
void input(){
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll u,v,w; scanf("%lld %lld %lld",&u,&v,&w);
		ed[i]=(Edge){u,v,w};
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
}
void solve(){
	sort(ed+1,ed+m+1);
	for(ll i=1;i<=n;i++) id[i]=i;
	ll cnt=0;
	for(ll i=1;i<=m;i++){
		ll u=ed[i].u,v=ed[i].v,w=ed[i].w;
		ll fu=find(u),fv=find(v);
		if(fu==fv) continue;
		cnt++; id[fu]=fv; ed[++nE]=ed[i];
		if(cnt==n-1) break;
	}
	for(ll i=1;i<=k;i++)
		for(ll j=1;j<=n;j++) ed[++nE]=(Edge){n+i,j,a[i][j]};
	nV=n+k; sort(ed+1,ed+nE+1);
	ll nPtn=(1<<k),ans=INF;
	for(ll p=0;p<nPtn;p++){
		ll res=0,nVn=n,cnt=0;
		for(ll i=1;i<=k;i++) ok[i]=0;
		for(ll i=1;i<=nV;i++) id[i]=i;
		for(ll i=1;i<=k;i++)
			if((p>>(i-1))&1){
				res+=c[i];
				ok[i]=1;
				nVn++;
			}
		if(res>=ans) continue;
		for(ll i=1;i<=nE;i++){
			ll u=ed[i].u,v=ed[i].v,w=ed[i].w;
			if(u>n&&(!ok[u-n])) continue;
			ll fu=find(u),fv=find(v);
			if(fu==fv) continue;
			cnt++; res+=w; id[fu]=fv;
			if(res>=ans) break;
			if(cnt==nVn-1) break;
		}
		ans=min(res,ans);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	solve();
	return 0;
}

