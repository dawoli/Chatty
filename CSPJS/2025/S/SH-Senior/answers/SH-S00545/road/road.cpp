#include <bits/stdc++.h>
using namespace std;
struct F{
	int k,w;
};
int n,m,k,c[15],vis[10010],s,minn=INT_MAX;
vector<F> g[10010];
queue<int> que;
int dfs(int u){
	int flag=0;
	for(int i=2;i<=n;++i){
		if(!vis[i]) flag=1;
	}
	if(flag){
		vis[u]=1;
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i].k,w=g[u][i].w;
			if(!vis[v]){
				if(v>4) s+=c[v-m];
				s+=w;
				vis[v]=1;
				dfs(v);
				vis[v]=0;
				s-=w;
				if(v>4) s-=c[v-m];
			}
		}
	}
	else if(s<minn) minn=s;
	
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		g[u].push_back((F){v,w});
		g[v].push_back((F){u,w});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1,w;j<=m;++j){
			cin>>w;
			g[j].push_back((F){m+i,w});
			g[m+i].push_back((F){j,w});
		}
	}
	dfs(1);
	cout<<minn;
	return 0;
}
