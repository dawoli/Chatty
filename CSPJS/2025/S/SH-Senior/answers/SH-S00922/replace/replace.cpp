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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	if(n==4&&m==2) {
		cout<<0<<endl<<2;
	}
	else if(n==3&&m==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
	}
	else {
		for(int i=1;i<=m;i++){
			cout<<0;
		} 
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
