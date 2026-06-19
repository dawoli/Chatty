#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=1e4+15;
int n,m,k;
ll ans=1e18;
int c[N],a[10][N],fa[N],vis[15];
struct edge{
	int u,v,w;
};
vector<edge> e_fir;
vector<edge> e;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y)	fa[x]=y;
	else		return 1;
	return 0;
}
ll kruskal(){
	e.clear();
	ll res=0;
	int bud=0,tot=0;
	for(int i=0;i<e_fir.size();i++)	e.push_back(e_fir[i]);
	for(int i=1;i<=n+k;i++)	fa[i]=i;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			for(int j=1;j<=n;j++){
				e.push_back({i+n,j,a[i][j]});
			}
			res+=c[i];
			bud++;
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(unite(u,v))	continue;
		tot++;
		res+=w;
		if(tot==n+bud-1)	return res;
	}
	return 0x3f3f3f3f3f3f3f3f;
}
void dfs(int i){
	if(i==k){
		ans=min(ans,kruskal());
		return;
	}
	dfs(i+1);
	vis[i+1]=1;
	dfs(i+1);
	vis[i+1]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e_fir.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

