#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[1000010];
int c[15];
int vis[1000010];
int n,m,k;
int min_cost=INT_MAX;
void dfs(int now,int visited,int cost){
	if(visited==n){
		min_cost=min(min_cost,cost);
//		cout<<endl<<"This costs: "<<cost<<endl;
		return ;
	}
	for(auto i:g[now]){
		if(vis[i.first]<=2){
			vis[i.first]++;
//			cout<<"->"<<i.first;
			if(vis[i.first]==1)
				dfs(i.first,visited+1,cost+i.second);
			else
				dfs(i.first,visited,cost+i.second);
			vis[i.first]--;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int cost;
			cin>>cost;
			g[m+i].push_back({j,cost});
			g[j].push_back({m+i,cost});
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			cout<<i<<endl;
			dfs(i,0,0);
		}
		cout<<min_cost<<endl;
	}
	return 0;
}
