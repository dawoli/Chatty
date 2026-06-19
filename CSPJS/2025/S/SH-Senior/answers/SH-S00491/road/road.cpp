#include<bits/stdc++.h>
using namespace std;
#define sc cerr
#define qlog(a) {sc<<#a<<"="<<a<<"\n";}
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define qloga(a,l,r) {sc<<#a<<" : ";rep(I,l,r){sc<<a[I]<<" ";}sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<" : ";for(auto I:a){sc<<I<<" ";}sc<<"\n";}
typedef long long ll;

#define int ll
const int N=1e4+50;
int n,m,k;

struct Edge{
	int u,v,w;
	bool operator < (const Edge &AT){
		return w<AT.w;
	}
};
int c[30],a[12][N];
ll ans=9e18;
vector<Edge> e;
vector<Edge> vl;

int fa[N];

void initbcj(){
	rep(i,1,n+20)fa[i]=i;
}
int rt(int u){
	if(u==fa[u])return u;
	return fa[u]=rt(fa[u]);
}
void merge(int u,int v){
	fa[rt(u)]=fa[rt(v)];
}
vector<Edge> r;

ll Kruskal(){
	initbcj();
	r=e;
	sort(r.begin(),r.end());

	ll ctb=0; 
	for(const Edge &R:r){
		int u=R.u,v=R.v,w=R.w;
		if(rt(u)==rt(v))continue;
		merge(u,v);
		ctb+=w;	
	}
	return ctb;
}

void dfs(int cur=1,ll delta=0){
	if(cur>k){
		//for(const Edge &AT:e){sc<<AT.u<<" "<<AT.v<<"   "<<AT.w<<"\n";}sc<<"------------\n";
		ll ctb=Kruskal()+delta;
		ans=min(ans,ctb);
		return;
	}
	for(int i=1;i<=n;i++)e.push_back({n+cur,i,a[cur][i]});
	dfs(cur+1,delta+c[cur]);
	if(!c[cur])return;
	rep(i,1,n)e.pop_back();
	dfs(cur+1,delta);
}

void solve(){
	cin>>n>>m>>k;	
	rep(i,1,m){
		int u,v,w;	cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n)cin>>a[i][j];
	}

	initbcj();

	sort(e.begin(),e.end());
	for(const Edge &R:e){
		int u=R.u,v=R.v,w=R.w;
		if(rt(u)==rt(v))continue;
		merge(u,v);
		r.push_back({u,v,w});	
	}
	r.swap(e);

	dfs();	
	cout<<ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	solve();
}
