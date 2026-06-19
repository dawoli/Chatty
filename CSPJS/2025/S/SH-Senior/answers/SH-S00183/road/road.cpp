#include<bits/stdc++.h>
std::ifstream fin("road.in");
std::ofstream fout("road.out");
int n,m,k;
struct node{
	int u,v,w;
	bool operator < (const node x) const{
		return w<x.w;
	}
}e[1000006],b[11005],edge[110005];
int fa[11005],cnt,tot,point;
void init(){
	for(int i=1;i<=point;i++){
		fa[i]=0;
	}
}
int find(int x){
	if(fa[x]==0) return x;
	return fa[x]=find(fa[x]);
}
int cost[12],a[12][10005];
long long best=1e18,ans=0;
bool used[12];

void work(){
	tot=0;
	point=n;
	for(int i=1;i<=cnt;i++){
		edge[++tot]=b[i];
	}
	for(int i=1;i<=k;i++){
		if(!used[i]) continue;
		point++;
		for(int j=1;j<=n;j++){
			edge[++tot]={point,j,a[i][j]};
		}
	}
	std::sort(edge+1,edge+1+tot);
	init();
	for(int i=1;i<=tot;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			ans+=w;
			fa[fu]=fv;
		}
	} 
	best=std::min(best,ans);
}
void solve(int now,long long sum){
	if(now>k){
		ans=sum;
		work();
		return;
	} 
	used[now]=true;
	solve(now+1,sum+cost[now]);
	used[now]=false;
	solve(now+1,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w; fin>>u>>v>>w;
		e[i]={u,v,w};
	}
	std::sort(e+1,e+1+m); 
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			b[++cnt]={u,v,w};
			fa[fu]=fv;
		}
	}
	for(int i=1;i<=k;i++){
		fin>>cost[i];
		for(int j=1;j<=n;j++){
			fin>>a[i][j];
		}
	}
	solve(1,0);
	fout<<best<<"\n";
} 

