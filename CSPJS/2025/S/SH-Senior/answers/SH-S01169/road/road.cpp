#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],way[10005],n;
bool vis[10005];
long long cst=0,ncst=0;
void dfs(int k){
	if(k==n){
		cst=max(cst,ncst);
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		if(a[way[k]][i]==-1) continue;
		way[k+1]=i;
		vis[i]=true;
		ncst+=a[way[k]][i];
		dfs(k+1);
		ncst-=a[way[k]][i];
		vis[i]=false;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) a[i][j]=-1;
		}
		for(int i=0;i<m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			if(u!=v) a[u][v]=a[v][u]=min(a[u][v],w);
		}
		for(int i=0;i<n;i++){
			vis[i]=true;
			way[1]=i;
			dfs(1);
			vis[i]=false;
		}
		cout<<cst;
		return 0;
	}
	int a[n+k][n+k],c[k];
	for(int i=0;i<n+k;i++){
		for(int j=0;j<n+k;j++) a[i][j]=-1;
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u!=v) a[u][v]=a[v][u]=min(a[u][v],w);
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++) cin>>a[j][n+i],a[n+i][j]=a[j][n+i];
	}
}
