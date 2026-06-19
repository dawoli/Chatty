#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+1;
struct rd{
	int v,w;
};
int n,m,k,c[11],a[11][N];
vector<rd> to[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		to[u].push_back(rd{v,w});
		to[v].push_back(rd{u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	return 0;
} 
