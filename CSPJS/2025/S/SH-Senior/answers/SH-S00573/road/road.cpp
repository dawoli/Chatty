#include<bits/stdc++.h>
#define N 10015
#define M 1000005
#define K 10
using namespace std;
int n,m,k,c[K],id[N],sz[N];
long long ans;
int ccc;
struct edge{int u,v,w;};
vector<edge> es,nes,aes[K];
bool operator<(const edge &x,const edge &y){
	return make_tuple(x.w,x.u,x.v)<make_tuple(y.w,y.u,y.v);
}
int find(int x){
	++ccc;
	return id[x]==x?x:id[x]=find(id[x]);
}
vector<edge> ssolve(vector<edge> &tes,long long cst=0){
	// cerr<<cst<<' ';
	vector<edge> res;
	for(int i=1;i<=n+k;i++)id[i]=i,sz[i]=1;
	for(auto x:tes){
		int u=find(x.u),v=find(x.v);
		if(u!=v){
			if(sz[u]<sz[v])swap(u,v);
			sz[u]+=sz[v],id[v]=u;
			res.push_back(x);
			cst+=x.w;
		}
	}
	// cerr<<cst<<'\n';
	ans=min(ans,cst);
	return res;
}
void dfs(int i,long long cst,vector<edge> tes){
	if(i==k){
		return;
	}
	dfs(i+1,cst,tes);
	cst+=c[i];
	int ssz=(int)tes.size();
	for(auto x:aes[i]){
		tes.push_back(x);
	}
	inplace_merge(tes.begin(),tes.begin()+ssz,tes.end());
	dfs(i+1,cst,ssolve(tes,cst));
}
void solve(){
	ans=1e18;
	cin>>n>>m>>k;
	es.resize(m);
	for(auto &x:es){
		cin>>x.u>>x.v>>x.w;
	}
	stable_sort(es.begin(),es.end());
	nes=ssolve(es);
	for(int i=0;i<k;i++){
		cin>>c[i];
		aes[i].resize(n);
		for(int j=0;j<n;j++){
			aes[i][j].u=j+1;
			aes[i][j].v=n+i+1;
			cin>>aes[i][j].w;
		}
		stable_sort(aes[i].begin(),aes[i].end());
	}
	dfs(0,0,nes);
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	// cerr<<ccc<<'\n';
	return 0;
}
