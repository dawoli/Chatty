#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long
#define cll const long long
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
cll N=10009,M=1e6+9,K=12;
ll a[K][N],c[K],n,m,k;
struct Edge{ll to,nxt,w;}e[M<<1]; ll nE,hd[N];
void addedge(ll u,ll v,ll w){
	e[++nE]=(Edge){v,hd[u],w}; hd[u]=nE;
	e[++nE]=(Edge){u,hd[v],w}; hd[v]=nE;
}
namespace K0{
	struct edge{
		ll u,v,w;
		bool operator<(const edge&e)const{return w<e.w;}
	}E[M];
	ll id[N]; ll root(ll u){return id[u]==u?u:id[u]=root(id[u]);}
	void solve(){
		ll x=0;
		rep(u,1,n)for(ll i=hd[u];i;i=e[i].nxt)if(u<e[i].to)E[++x]=(edge){u,e[i].to,e[i].w};
		rep(u,1,n)id[u]=u;
		sort(E+1,E+1+x);
		ll ans=0;
		rep(i,1,x){
			ll u=E[i].u,v=E[i].v,w=E[i].w;
			if(root(u)==root(v))continue;
			ans+=w; id[root(u)]=root(v);
		}
		cout<<ans<<"\n";
	}
}
void cmin(ll&x,ll y){
	if(x==0)x=y;
	else x=min(x,y);
}
namespace SpeA{
	struct edge{
		ll u,v,w;
		bool operator<(const edge&e)const{return w<e.w;}
	}E[M+N*K+K];
	ll id[N+2*K],x=0; ll root(ll u){return id[u]==u?u:id[u]=root(id[u]);}
	ll pc(ll x){ll ans=0; while(x)ans++,x&=x-1;return ans;}
	ll mst(){
		ll ans=0,nE=n+2*k-1;
		rep(u,1,n+2*k)id[u]=u;
		rep(i,1,x){
			ll u=E[i].u,v=E[i].v,w=E[i].w;
			if(root(u)==root(v))continue;
			ans+=w; id[root(u)]=root(v); nE--;
			if(!nE)return ans;
		}
		return ans;
	}
	void solve(){
		rep(u,1,n)for(ll i=hd[u];i;i=e[i].nxt)if(u<e[i].to)E[++x]=(edge){u,e[i].to,e[i].w};
		rep(i,1,k){
			E[++x]=(edge){n+i,n+i+k,c[i]};
			rep(j,1,n)E[++x]=(edge){n+i,j,a[i][j]};
		}
		sort(E+1,E+1+x);cout<<mst()<<"\n";
	}
}
namespace dth{
	struct edge{
		ll u,v,w;
		bool operator<(const edge&e)const{return w<e.w;}
	}E[M+N*K+K];
	ll id[N+2*K],x=0; ll root(ll u){return id[u]==u?u:id[u]=root(id[u]);}
	bool ban(ll st,ll x){if(x<=n)return 0; ll y=x-n-1; if(y>=k)y-=k; return st>>y&1;}
	ll pc(ll x){ll ans=0; while(x)ans++,x&=x-1;return ans;}
	ll mst(ll st){
		ll ans=0,nE=n+2*(k-pc(st))-1;//cout<<nE<<" ";
		rep(u,1,n+2*k)id[u]=u;
		rep(i,1,x){
			ll u=E[i].u,v=E[i].v,w=E[i].w;
			if(root(u)==root(v)||ban(st,u)||ban(st,v))continue;
			ans+=w; id[root(u)]=root(v); nE--;
			if(!nE)return ans;
		}
		return ans;
	}
	void solve(){
		rep(u,1,n)for(ll i=hd[u];i;i=e[i].nxt)if(u<e[i].to)E[++x]=(edge){u,e[i].to,e[i].w};
		rep(i,1,k){
			E[++x]=(edge){n+i,n+i+k,c[i]};
			rep(j,1,n)E[++x]=(edge){n+i,j,a[i][j]};
		}
		sort(E+1,E+1+x);ll ans=1e18;
		rep(i,0,(1<<k)-1)ans=min(ans,mst(i));//,cout<<i<<":"<<mst(i)<<endl;
		cout<<ans<<"\n";
	}
}
void work(){
	cin>>n>>m>>k;
	rep(i,1,m){ll u,v,w;cin>>u>>v>>w;addedge(u,v,w);}
	bool A=1;
	rep(i,1,k){
		cin>>c[i]; A&=(c[i]==0);
		ll mn=1; rep(j,1,n)cin>>a[i][j],mn=min(mn,a[i][j]);
		A&=(mn==0);
	}
	if(!k)K0::solve();
	else if(A)SpeA::solve();
	else dth::solve();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T=1;///cin>>T;
	while(T--)work();
	return 0;
}

