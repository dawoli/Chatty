#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,ans,vis[N],cnt=10010;
struct P{
	int v,w;
};
vector<pair<int,int> > g[N];
void d(int u,int fa,int ans) {
	bool f=0;
	for(int i=1;i<=n;++i) if(vis[i]!=1) {f=1;break;}
	if(f==0) {
		cnt=min(cnt,ans);
		return;
	}
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i].first;
		int w=g[u][i].second;
		if(vis[v]==1) continue;
		vis[v]=1;
		d(v,u,ans+w);
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vis[1]=1;
	d(1,0,0);
	cout<<cnt<<endl;
	return 0;
} 
