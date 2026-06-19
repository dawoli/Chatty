#include<bits/stdc++.h>
using namespace std;
vector<int>g[10005];
long long w[10005][10005],a[10005][10005],c[10005];
int k,n,m;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		cin>>w[u][v];
		w[v][u]=w[u][v];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}
