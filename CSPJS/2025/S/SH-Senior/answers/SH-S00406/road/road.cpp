#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],a[15][10005],fa[10005],maxn=0x3f3f3f3f3f3f3f3f;
int vis[10005];
vector<pair<int,int> > G[10005],e[15],e2[10005];
struct edge{
	int u,v,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return false;
	fa[x]=y;
	return true;
}
int solve(int con){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(con&(1<<(i-1))){
			cnt+=c[i];
		}
	}
	priority_queue<pair<int,int> > q;
	vis[1]=1;
	for(auto it:G[1]){
		q.push({-it.second,it.first});
	}
	if(con&1){
		for(auto it:e[1]){
			q.push({-it.second,it.first});
		}
	}
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		if(vis[t.second]) continue;
		merge(1,t.second);
		vis[t.second]=1;
		for(auto it:G[t.second]){
			if(!vis[it.first]){
				q.push({-it.second,it.first});
			}
		}
		if(t.second<=k&&con&(1<<t.second)){
			for(auto it:e[t.second]){
				if(vis[it.first]) continue;
				q.push({-it.second,it.first});
			}
		}
		for(auto it:e2[t.second]){
			if(vis[it.first]) continue;
			if(con&it.first){
				q.push({-it.second,it.first});
			}
		}
		cnt-=t.first;
	}
	return cnt;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		if(c[i]!=0) flag=false;
		cin >> c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin >> w;
			e[i].push_back({j,w});
			e2[j].push_back({i,w});
		}
	}
	if(flag){
		cout << solve((1<<k-1));
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		int ans=solve(i);
		maxn=min(ans,maxn);
	}
	cout << maxn;
	return 0;
}
