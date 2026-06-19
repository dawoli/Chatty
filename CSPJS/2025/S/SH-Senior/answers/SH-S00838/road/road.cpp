#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define fir first
#define sec second

constexpr int N = 1e4+111;

int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge &o)const{return w<o.w;}
};
int fa[N];
ll pri[10];
int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}

vector<edge> vc[10];
vector<edge> mg(const vector<edge> &a,const vector<edge> &b){
	auto pt=b.begin();
	vector<edge> res;
	iota(fa+1,fa+n+k+1,1);
	auto chk=[&](edge e){
		int u=find(e.u),v=find(e.v);
		if(u!=v)fa[u]=v,res.push_back(e);
	};
	for(auto e:a){
		while(pt!=b.end()&&pt->w<e.w)chk(*pt),++pt;
		chk(e); 
	}
	while(pt!=b.end())chk(*pt),++pt;
	return move(res);
}
ll ans=1e18;
void dfs(int x,const vector<edge> &nw,ll sum){
	ll t=sum;for(auto e:nw)t+=e.w;
	ans=min(ans,t);
	rep(i,x+1,k-1)dfs(i,mg(nw,vc[i]),sum+pri[i]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m>>k;
	vector<edge> z(m);
	for(auto &e:z)cin>>e.u>>e.v>>e.w;
	sort(z.begin(),z.end()),z=mg(z,{});
	repn(j,k){
		cin>>pri[j];vc[j].resize(n);
		repn(i,n){int x;cin>>x;vc[j][i]={j+n+1,i+1,x};}
		sort(vc[j].begin(),vc[j].end());
	}
	dfs(-1,z,0);
	cout<<ans<<'\n';
}
