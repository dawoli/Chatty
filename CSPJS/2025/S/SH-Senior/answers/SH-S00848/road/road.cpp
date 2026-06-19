#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,m,k,u[MAXN],v[MAXN],w[MAXN];
vector<int> g,g2;
struct edge{
	int u,v,w;
};
bool cmp(edge x,edge y){
	if(x.w<y.w) return 1;
	else if(x.w==y.w&&x.u<y.u) return 1;
	return 0;
}
int dfs(int u,int fa){
	if(u==fa) return 0;
	for(auto v:g[u]){
		if(g2[u].find(v)!=0){
			return 0;
		}
		return dfs(u,v);
		g2[u].push_back(v);
	}
}
void solve1(){
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	cout<<ans<<endl;
}
void solve2(){
	edge abc[MAXN];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		abc[i].u=u[i];
		abc[i].v=v[i];
		abc[i].w=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	vector<int> g,g2;
	map<int,int> mp[i];
	for(int i=1;i<=n;i++){
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(v[i]);
		mp[u[i]][v[i]]==w[i];
	}
	sort(abc+1,abc+1+n,cmp);
	cout<<dfs(1,1)<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0) solve1();
	else     solve2();
	return 0;
}
