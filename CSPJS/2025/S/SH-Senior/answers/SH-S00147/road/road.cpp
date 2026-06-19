#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,m,k;
int g[10010][10010];
int c[20],a[20][10010];
#define pii pair<int,int>
//struct 
//vector<pair<int,int>> g[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=0;i<k;i++){
		scanf("%d",c[i]);
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	return 0;
}
