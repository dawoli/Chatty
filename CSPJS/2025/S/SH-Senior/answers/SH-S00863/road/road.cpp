#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1000009;
const ll N=100009;
const ll K=10;
ll n,m,k,c[K],a[K][N],rt[N*2],f[K];
struct edge{
	ll u,v,w;
}e[M*2],ee[M*2];
bool cmp(const edge&p,const edge&q){
	if(p.w<q.w){
		return true;
	}else{
		return false;
	}
}
bool sch(ll&u,ll&v){
	if(u==v){
		return true;
	}
	if(rt[u]==u && rt[v]==v){
		return false;
	}
	u=rt[u];
	v=rt[v];
	return sch(u,v);
}
void unite(ll u,ll v){
	if(u>v){
		swap(u,v);
	}
	rt[v]=rt[u];
	return;
}
void solvea(){
	for(ll i=1;i<=n;i++){
		rt[i]=i;
	}
	sort(e+1,e+1+m,cmp);
	ll nw=1;
	ll ans=0;
	for(ll timer=1;timer<=n-1;timer++){
		ll u=e[nw].u;
		ll v=e[nw].v;
		while(sch(u,v)){
			nw++;
			u=e[nw].u;
			v=e[nw].v;
		}
		unite(u,v);
		ans+=e[nw].w;
	}
	printf("%lld\n",ans);
	cout<<ans<<endl;
	return;
}
void cf(ll kkk){
	for(ll i=k;i>=0;i--){
		f[i]=0;
		if(kkk>=(1<<i)){
			f[i]=1;
			kkk-=(1<<i);
		}
	}
	return;
}
ll solve2(){
	ll cnt=0;
	ll ans=0;
	ll cnt2=m;
	for(ll i=1;i<=m;i++){
		ee[i]=(edge){e[i].u,e[i].v,e[i].w};
	}
	for(ll i=0;i<k;i++){
		if(f[i]){
			cnt++;
			ans+=c[i+1];
			for(ll j=1;j<=n;j++){
				cnt2++;
				ee[cnt2]=(edge){n+i+1,j,a[i+1][j]};
			}
		}
	}
	sort(ee+1,ee+1+cnt2,cmp);
	ll nw=1;
	for(ll i=1;i<=n+k;i++){
		rt[i]=i;
	}
	for(ll timer=1;timer<n+cnt;timer++){
		ll u=ee[nw].u;
		ll v=ee[nw].v;
		while(sch(u,v)){
			nw++;
			u=ee[nw].u;
			v=ee[nw].v;
		}
		unite(u,v);
		ans+=ee[nw].w;
	}
	return ans;
}
void solve(){
	ll nptn=(1<<k);
	ll ans=1e16;
	for(ll ptn=0;ptn<nptn;ptn++){
		cf(ptn);
		ans=min(ans,solve2());
	}
	printf("%lld\n",ans);
	return;
}
void solvefst(){
	ll ans=0;
	ll cnt2=m;
	for(ll i=1;i<=m;i++){
		ee[i]=(edge){e[i].u,e[i].v,e[i].w};
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++){
			cnt2++;
			ee[cnt2]=(edge){n+i,j,a[i][j]};
		}
	}
	sort(ee+1,ee+1+cnt2,cmp);
	ll nw=1;
	for(ll i=1;i<=n+k;i++){
		rt[i]=i;
	}
	for(ll timer=1;timer<n+k;timer++){
		ll u=ee[nw].u;
		ll v=ee[nw].v;
		while(sch(u,v)){
			nw++;
			u=ee[nw].u;
			v=ee[nw].v;
		}
		unite(u,v);
		ans+=ee[nw].w;
	}
	printf("%lld\n",ans);
	return;
}
bool ck(){
	for(ll i=1;i<=k;i++){
		if(c[i]!=0){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&e[i].u);
		scanf("%lld",&e[i].v);
		scanf("%lld",&e[i].w);
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0){
		solvea();
	}else if(ck()){
		solvefst();
	}else{
		solve();
	}
	return 0;
}
