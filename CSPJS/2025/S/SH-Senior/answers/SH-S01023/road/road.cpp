#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[15],a[15][10005];
struct edge{
	int to;
	int price;
};
vector<edge> g[1000005];
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
			cin>>a[i][j];
		} 
	}
	return 0;
}
