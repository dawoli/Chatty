#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
vector<int>adj[1009];
int cst[1009][1009];
int c[19],a[19][1009];
bool vis[1009][1009];
int rd;
void dfs(int u,int sum){
	for(int v=0;v<adj[u].size();v++){
		if(!vis[u][v]){
			vis[u][v]=1,vis[v][u]=1;
			dfs(v,sum+cst[u][v]);
			vis[u][v]=0,vis[v][u]=0;
		}
	}
	rd=max(sum,rd);
	return;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		cst[u][v]=w,cst[v][u]=w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		cout<<rd<<endl;
	}
	else{
		int minn=1e9;
		for(int i=0;i<k;i++){
			minn=min(minn,c[i]);
		}
		cout<<rd<<endl;
	}
	return 0;
} 
