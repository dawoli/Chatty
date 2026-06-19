#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,cost;
};
vector<node> ve[10004];
vector<node> ve2[10004];
int gz[10004];
int vis[10004]={0};
int ans=1e9;
void dfs(int x,int cost){
	if(vis[x]){
		ans=min(ans,cost);
		return ;
	}
	for(node i :ve[x]){
		vis[x]=1;
		dfs(i.to,cost+i.cost);
		vis[x]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	}
	for(int i =1;i<=k;i++){
		cin>>gz[i];
		for(int j = 1;j<=n;j++){
			int x;cin>>x;
			ve2[i].push_back({j,x});
			ve2[j].push_back({i,x}); 
		}
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
