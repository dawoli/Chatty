#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,m,k;
//int connect[10001][10001];
//int city[10011][10011];
int road[10001][10001];
int country[11][10001];
bool vis[100001]={false};
bool flag[11]={false};
//void dfs(int pos){
//	
//	for(int i=1;i<=n;i++){
//		if(vis[i]){
//			for(int j=1;j<=n;j++){
//			if()
//		}
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			road[i][j]=2147483647;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road[u][v]=road[v][u]=w;
//		city[u][v]=city[v][u]=w;
	}
	bool A=true;
	for(int i=1;i<=k;i++){
		cin>>country[i][0];
		if(country[i][0]!=0)A=false;
		for(int j=1;j<=n;j++){
			cin>>country[i][j];
			if(country[i][j]!=0)A=false;
//			city[n+i][j]=country[i][j];
		}
	}
	//A-32
	if(A){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int t=1;t<=n;t++){
		int addpos;
		int addlenth=1e9+7;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++){
					if(!vis[j] && road[i][j]<addlenth){
						addlenth=road[i][j];
						addpos=j;
					}
				}
			}
		}
		vis[addpos]=true;
		ans+=addlenth;
	}
	cout<<ans;
//	vis[1]=true;
//	dfs(1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<city[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	return 0;
} 
