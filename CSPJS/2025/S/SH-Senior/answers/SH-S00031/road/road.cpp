#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1200009;
const ll N=10009;
const ll P=13;
ll n,m,k,c[N],f[N][P],fa[N];
bool ifA=true;
struct Edge{ll u,v,w;}e[M];
bool cmp(const Edge&x,const Edge&y){
	return x.w<y.w;
}
ll find(ll u){
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
void solve1234(){
	sort(e+1,e+1+m,cmp);
	for(ll i=1;i<=n;i++) fa[i]=i;
	ll cnt=0,ans=0;
	for(ll i=1;i<=m;i++){
		if(cnt==n-1) break;
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		fa[u]=find(u),fa[v]=find(v);
		if(fa[u]==fa[v]) continue;
		cnt++; ans+=w; fa[u]=fa[v];
	}
	cout<<ans<<endl;
}
void solveA(){
	for(ll p=1;p<=k;p++){
		ll pnt=0;
		for(ll i=1;i<=n;i++) if(f[p][i]==0){pnt=i; break;}
		for(ll i=1;i<=n;i++) if(i!=pnt) e[++m]=(Edge){pnt,i,f[p][i]};
	}
	sort(e+1,e+1+m,cmp);
	for(ll i=1;i<=n;i++) fa[i]=i;
	ll cnt=0,ans=0;
	for(ll i=1;i<=m;i++){
		if(cnt==n-1) break;
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		fa[u]=find(u),fa[v]=find(v);
		if(fa[u]==fa[v]) continue;
		cnt++; ans+=w; fa[u]=fa[v];
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(ll p=1;p<=k;p++){
		cin>>c[p]; if(c[p]!=0) ifA=false;
		for(ll i=1;i<=n;i++) cin>>f[p][i];
	}
	if(k==0) solve1234();
	else solveA();
	return 0;
}

