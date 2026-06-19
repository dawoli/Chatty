#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define K 15
struct Edge{
	int u,v;
	long long w;
	int d;
	bool operator < (const Edge &b) const{
		return w<b.w;
	}
};
vector<Edge> edges;
int n,m,k;
long long t[K];
long long res=1e18;
bool av[K];
int fa[N+K];
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;}
}
int find(int x){
	if(fa[x]==x){return x;}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int rx=find(x),ry=find(y);
	fa[rx]=ry;
}
void kruskal(long long t,int c){
	init(n+k);
	int edgeNum=0;
	long long ans=0;
	for(Edge e:edges) if(av[e.d]){
		int u=e.u,v=e.v;
		long long w=e.w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
			if(++edgeNum==n+c-1){
				break;}
		}
	}
	res=min(res,ans+t);
}
void dfs(int i,long long w,int c){
	if(i==k+1){
		kruskal(w,c);
		return;
	}
	av[i]=true;
	dfs(i+1,w+t[i],c+1);
	av[i]=false;
	dfs(i+1,w,c);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		edges.push_back(Edge{u,v,w,0});
	}
	long long mx=0;
	for(int i=1;i<=k;i++){
		cin>>t[i];
		mx=max(mx,t[i]);
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			mx=max(mx,w);
			edges.push_back(Edge{n+i,j,w,i});
		}
	}
	av[0]=true;
	sort(edges.begin(),edges.end());
	dfs(1,0,0);
	cout<<res<<'\n';
	return 0;
}
