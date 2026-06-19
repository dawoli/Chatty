#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int r[N][N];
int c[N][N],cv[N],sub[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>r[u][v];
		r[v][u]=r[u][v];
	}
	for(int i=1;i<=k;i++){
		cin>>cv[i];
		sub[i]+=cv[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			sub[i]+=c[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,sub[i]);
	}
	cout<<ans<<endl;
	return 0;
}
