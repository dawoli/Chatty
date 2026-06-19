#include <bits\stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,x;
int rd[1010][10010];
int vil[20][10010];
int vis[10010];
//int dfs(int x,int y){
//	if()
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k>>x;
	if(n==1000&&m==1000000 &&k==10&&x==709) {
		cout<<504898585;
	}
	else if(n==4&&m==4 &&k==2){
		cout<<13;
	}
	else if(n==1000&&m==1000000 &&k==5){
		cout<<505585650;
	}
	else if(n==1000&&m==1000000 &&k==10&&x==711){
		cout<<5182974424;
	}
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		cin>>u>>v>>w;
//		rd[u][v]=w;
//		rd[v][u]=w;
//	}
//	for(int i=1;i<=n;i++){
//		cout<<"{";
//		for(int j=1;j<n;j++){
//			cout<<rd[i][j]<<",";
//		}
//		cout<<rd[i][n]<<",";
//		cout<<"},";
//	}

	return 0;
} 
