#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,a[N][N],xc[15][N],ans=2147483647;
vector<int> g[N];
bool vis[N];
bool check() {
	for(int i=1;i<=n;i++)
		if(!vis[i]) return false;
	return true;
}
void dfs(int city,int cost ){
	vis[city]=1;
	if(cost>=ans) return ;
	if(check()) {
		ans=min(ans,cost);
		return ;
	}
	for(int i=0;i<g[city].size();i++){
		if(vis[g[city][i]]!=1){
			vis[g[city][i]]=1;
			int mb=2147483647,bh=2147483647;
			for(int j=1;j<=k;j++)
				if(mb>xc[j][g[city][i]]||(mb==xc[j][g[city][i]]&&bh>j)){
					mb=xc[j][g[city][i]];
					bh=j;
				}
			int zh=mb+bh;
			if(zh<a[city][g[city][i]])dfs(g[city][i],cost+zh);
			else dfs(g[city][i],cost+a[city][g[city][i]]);
//			cout<<cost<<" "<<zh<<" "<<city<<" "<<g[city][i]<<endl;
			vis[g[city][i]]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,cost;
		cin>>u>>v>>cost;
		g[u].push_back(v);
		g[v].push_back(u);
		a[u][v]=a[v][u]=cost;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			cin>>xc[i][j];
	dfs(1,0);
	cout<<ans;
	return 0;
}
