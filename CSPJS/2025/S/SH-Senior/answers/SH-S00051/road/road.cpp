#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define K 15
typedef long long ll;
using namespace std;
struct Edge{
	ll u,v,w;
	bool operator<(const Edge&b)const{
		return w<b.w;
	}
}e[M*4];
ll n,m,k,tot,ans,a[K][N],c[N],f[N];
ll find(ll x){ return f[x]==x?x:f[x]=find(f[x]); }
void Solve1_4(){
	for(ll i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+1+tot);
	for(ll i=1,j=0;(i<=tot&&j<n-1);i++){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		f[find(u)]=f[find(v)];
		j++,ans+=w;
	}
	cout<<ans;
}
bool A(){
	for(ll i=1;i<=k;i++){
		if(c[i]) return 0;
		bool fd=false;
		for(ll j=1;j<=n;j++) if(a[i][j]==0) fd=true;
		if(!fd) return 0;
	}
	return 1;
}
void SolveA(){
	for(ll i=1;i<=n;i++) for(ll j=1;j<i;j++) for(ll t=1;t<=k;t++){
		ll tmp=a[t][i]+a[t][j];
		e[++tot]={i,j,tmp};
		e[++tot]={j,i,tmp};
	}
	for(ll i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+1+tot);
	for(ll i=1,j=0;(i<=tot&&j<n-1);i++){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		f[find(u)]=f[find(v)];
		j++,ans+=w;
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[++tot]={u,v,w};
		e[++tot]={v,u,w};
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0) Solve1_4();			//16pts
	else if(A()) SolveA();			//32pts(´í½â£¬ÓÚ17:30·ÅÆú)
	return 0;
}
