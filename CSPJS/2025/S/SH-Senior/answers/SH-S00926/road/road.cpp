//最小生成树 且可加结点 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Road{
	int u,v,w;
}g[1000005];
long long ans;
bool vis[100015];
int c[13];
int a[13][100005];
int ci[1005][1005];
int fa[1005];
bool cmp(Road x,Road y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){			//16
		for(int i=1;i<=m;i++){
			cin>>g[i].u>>g[i].v>>g[i].w;
		}
		sort(g+1,g+1+m,cmp);
		for(int i=1;i<=m;i++){
			if(find(g[i].u)!=find(g[i].v)){
				ans+=g[i].w;
				fa[find(g[i].u)]=fa[find(g[i].v)];
			}
		}
		cout<<ans;
	}
	else{//c[i]==0时         32
		for(int i=1;i<=m;i++){//邻接表 
			int u,v,w;
			cin>>u>>v>>w;
			if(ci[u][v]!=0) ci[u][v]=ci[v][u]=min(w,ci[u][v]);
			else ci[u][v]=ci[v][u]=w;
		}
		for(int i=1;i<=k;i++){//直接利用村落建/更新边 
			cin>>c[i];
			int bn;
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]==0){
					bn=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(j==bn||a[i][j]==0) continue;
				if(ci[bn][j]!=0) ci[bn][j]=ci[j][bn]=min(ci[bn][j],a[i][j]);
				else ci[bn][j]=ci[j][bn]=a[i][j];
			}
		}
		m=0;
		for(int i=1;i<=n;i++){//改为边存 
			for(int j=1;j<=n;j++){
				if(ci[i][j]!=0) g[++m].u=i,g[m].v=j,g[m].w=ci[i][j];
//				cout<<g[m].u<<' '<<g[m].v<<' '<<g[m].w<<endl;
			}
		}
		
		sort(g+1,g+1+m,cmp);//建树 
		int cnt=0;
		for(int i=1;i<=m;i++){
//			cout<<g[i].w<<' ';
			if(find(g[i].u)!=find(g[i].v)){
				ans+=g[i].w;
				cnt++;
				fa[find(g[i].u)]=fa[find(g[i].v)];
			}
			if(cnt==n-1) break;
		}
		cout<<ans;
	}
	return 0;
} 
