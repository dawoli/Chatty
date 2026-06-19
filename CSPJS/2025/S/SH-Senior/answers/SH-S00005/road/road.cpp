#include<bits/stdc++.h>
using namespace std;
#define int long long
bool st;
int n,m,k;
int siz[1030];
struct Node{
	signed u,v,w;
}node[1000010],edge[11][10100],now[1030][10100];//将目前边集（带排序）存储在 now[目前状态] 中
int fa[10100];
int c[11];
int a[11][10010];
int find(int u){
	if(u==fa[u])return u;
	return fa[u]=find(fa[u]);
}
int ans=0x3f3f3f3f3f3f3f3f;
void dfs(int pos,int status,int curans,int cost){//一个是边集答案 一个是额外点答案
	if(pos==k+1){
		//已经有了答案 边集为 now
		ans=min(ans,curans+cost);
		return;
	}
	//不加状态继续
	dfs(pos+1,status,curans,cost);
	//加状态，合并边集（注意权值）
	cost+=c[pos];
	for(int i=1;i<=n+10;i++){
		fa[i]=i;
	}
	int npos=1,epos=1;
	int zong=0;
	int nstatus=status+(1<<(pos-1));
	while(npos<=siz[status]&&epos<=n){
		if(now[status][npos].w<=edge[pos][epos].w){
			int u=find(now[status][npos].u);
			int v=find(now[status][npos].v);
			if(u!=v){
				zong+=now[status][npos].w;
				fa[u]=v;
				now[nstatus][++siz[nstatus]]={now[status][npos].u,now[status][npos].v,now[status][npos].w};
			}
			npos++;
		}else{
			int u=find(edge[pos][epos].u);
			int v=find(edge[pos][epos].v);
			if(u!=v){
				zong+=edge[pos][epos].w;
				fa[u]=v;
				now[nstatus][++siz[nstatus]]={edge[pos][epos].u,edge[pos][epos].v,edge[pos][epos].w};
			}
			epos++;
		}
	}
	while(npos<=siz[status]){
		int u=find(now[status][npos].u);
		int v=find(now[status][npos].v);
		if(u!=v){
			zong+=now[status][npos].w;
			fa[u]=v;
			now[nstatus][++siz[nstatus]]={now[status][npos].u,now[status][npos].v,now[status][npos].w};
		}
		npos++;
	}
	while(epos<=n){
		int u=find(edge[pos][epos].u);
		int v=find(edge[pos][epos].v);
		if(u!=v){
			zong+=edge[pos][epos].w;
			fa[u]=v;
			now[nstatus][++siz[nstatus]]={edge[pos][epos].u,edge[pos][epos].v,edge[pos][epos].w};
		}
		epos++;
	}
	dfs(pos+1,nstatus,zong,cost);
}
bool ed;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>node[i].u>>node[i].v>>node[i].w;
	}
	sort(node+1,node+m+1,[](Node a,Node b){
		return a.w<b.w;
	});
	int bian=0;
	int yuan=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(node[i].u),v=find(node[i].v);
		if(u!=v){
			now[0][++bian]={node[i].u,node[i].v,node[i].w};
			fa[u]=v;
			yuan+=node[i].w;
		}
	}
	siz[0]=bian;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			edge[i][j]={n+i,j,a[i][j]};
		}
		sort(edge[i]+1,edge[i]+n+1,[](Node a,Node b){
			return a.w<b.w;
		});
	}
	dfs(1,0,yuan,0);
	cout<<ans;
	return 0;
}
