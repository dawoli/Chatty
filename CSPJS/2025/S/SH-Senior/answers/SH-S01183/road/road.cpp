#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
vector<pair<int,int>>g[N];
int c[N],a[N][N],road[N][N];
bool vis[N];
int ans=INT_MAX,n,m,k;
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
void dfsa(int u,int sum){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			flag=0;
			break;
		}
	}
	if(flag){
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		dfsa(i,sum+road[u][i]);
		vis[i]=0;
	}
}
int ansk=INT_MAX;
bool visk[N];
void dfsk(int u,int sum){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(visk[i]==0){
			flag=0;
			break;
		}
	}
	if(flag){
		ansk=min(ansk,sum);
		return ;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first,w=g[u][i].second;
		if(visk[v])continue;
		visk[v]=1;
		dfsk(v,sum+w);
		visk[v]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool A=1;
	cin>>n>>m>>k;
	memset(road,-1,sizeof road);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		road[u][v]=w;
		road[v][u]=w;
	}
	int root=1;
	for(auto u:g){
		sort(u.begin(),u.end(),cmp);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()==1)root=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)A=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j]; 
		}
		for(int j=1;j<=n;j++){
			for(int u=j+1;u<=n;u++){
				if(road[j][u]==-1)road[j][u]=road[u][j]=a[i][j]+a[i][u];
				else road[j][u]=road[u][j]=min(road[j][u],a[i][j]+a[i][u]);
			}
		}
	}
	if(k==0){
		visk[root]=1;
		dfsk(root,0);
		cout<<ansk;
	}else{
		vis[1]=1;
		dfsa(1,0);
		cout<<ans;
	}
	return 0;
}
