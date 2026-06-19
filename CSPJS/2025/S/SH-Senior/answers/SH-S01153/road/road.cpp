#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[10005][10005],indu[10005];
long long ans=-1;
bool vis[10005];
vector<int>g[10005];
void dfs(int r,int deep,long long s){
	if(deep==0){
		if(ans==-1) ans=s;
		else ans=min(ans,s);
	}
	vis[r]=1;
	for(int i=0;i<g[r].size();i++)
		if(!vis[g[r][i]])
		    dfs(g[r][i],deep-1,s+w[r][g[r][i]]);
    vis[r]=0;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,wi;
		cin>>u>>v>>wi;
		indu[u]++;
		indu[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
		w[u][v]=wi;
		w[v][u]=wi;
	}
	for(int i=1;i<=k;i++){
		int u,wi;
		cin>>u;
		for(int v=1;v<=n;v++){
			cin>>wi;
		}
	}
	for(int i=1;i<=n;i++)
		if(indu[i]==1) dfs(i,n-1,0);
	cout<<ans;
	return 0;
}
