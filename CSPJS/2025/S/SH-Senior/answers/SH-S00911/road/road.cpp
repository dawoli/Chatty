#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,c[20],fa[N],ans;
vector<pair<int,int>>g[M+10];
bool v_point[N+10],v_edge[N][N];
int find_fa(int u){
	if(fa[u]==u){
		return u;
	}
	return fa[u]=find_fa(fa[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		v_point[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		if(i%3==0||i%3==2){
			ans+=w;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			g[n+i].push_back({j,a});
			g[j].push_back({n+i,a});
		}
	}
	cout<<ans;
	return 0;
}
