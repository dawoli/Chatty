#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,fei;
int roadlist[10010][10010];
int vis[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(roadlist[u][v]==0){
			roadlist[u][v]=w;
			roadlist[v][u]=w;
		}
		else{
			roadlist[u][v]=min(roadlist[u][v],w);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=ans+roadlist[i][j];
		}
	}
	cout<<ans/2;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>fei;
		}
	}
	
	return 0;
}
