#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
	int ed;
	int w;
};
vector<edge> graph[20005];
int c[15];
int a[15][10005];
pair<int,pair<int,int> > p[2000006];
int fa[20005];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]); return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	bool fflag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0) fflag=0;
		bool flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) flag=1;
		}
		if(flag==0) fflag=0;
	}
	if(fflag){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<graph[i].size();j++){
				int nxt=graph[i][j].ed;
				int w=graph[i][j].w;
				if(nxt>i){
					cnt++;
					p[cnt]={w,{i,nxt}};
				}
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				cnt++;
				p[cnt]={a[i][j],{j,n+i}};
			}
		}
		int res=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(p+1,p+cnt+1);
		for(int i=1;i<=cnt;i++){
			int u=p[i].second.first;
			int v=p[i].second.second;
			int w=p[i].first;
			if(find(u)!=find(v)){
				fa[fa[u]]=fa[v];
				res+=w;
			}
		}
		cout<<res;
		return 0;
	}
	int ans=1e16;
	for(int ppp=0;ppp<(1<<k);ppp++){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<graph[i].size();j++){
				int nxt=graph[i][j].ed;
				int w=graph[i][j].w;
				if(nxt>i){
					cnt++;
					p[cnt]={w,{i,nxt}};
				}
			}
		}
		int res=0;
		for(int i=1;i<=k;i++){
			if((ppp>>(i-1))&1) continue;
			res+=c[i];
			for(int j=1;j<=n;j++){
				cnt++;
				p[cnt]={a[i][j],{j,n+i}};
			}
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(p+1,p+cnt+1);
		for(int i=1;i<=cnt;i++){
			int u=p[i].second.first;
			int v=p[i].second.second;
			int w=p[i].first;
			if(find(u)!=find(v)){
				fa[fa[u]]=fa[v];
				res+=w;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
}
