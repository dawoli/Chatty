#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10017;
int n,m,k,nQ,fa[N],vis[17],eid[17][N],p[17][N],q[N<<1],top[17];
ll ans,c[17];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
bool merge(int u,int v){
	u=getfa(u);v=getfa(v);
	if (u==v) return 0;
	fa[v]=u;
	return 1;
}
struct edge{
	int u,v;ll w;
}e[120007],tmp[1000007];
bool cmp(const edge& a,const edge& b){return a.w<b.w;}
void reduce_edges(){
	for (int i=1;i<=n;++i){
		fa[i]=i;
	}
	int cnt=0;
	for (int i=1;i<=m;++i){
		if (merge(tmp[i].u,tmp[i].v)){
			e[++cnt]=tmp[i];
			ans+=tmp[i].w;
			if (cnt==n-1){
				break;
			}
		}
	}
//	assert(cnt==n-1);
	m=cnt;
}
void Kruskal(int id,int cnt){
	top[id]=0;
	for (int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	ll s=0;
	for (int i=1;i<=k;++i){
		if (vis[i]){
			s+=c[i];
		}
	}
	for (int i,j=1;j<=nQ;++j){
		i=q[j];
		if (merge(e[i].u,e[i].v)){
			s+=e[i].w;
			p[id][++top[id]]=i;
			if ((--cnt)==1){
				break;
			}
		}
	}
	ans=min(ans,s);
}
void dfs(int u,int s){
	if (u) Kruskal(u,n+s);
	for (int i=u+1;i<=k;++i){
		vis[i]=1;
		nQ=0;
		int x=1,y=1;
		while(x<=top[u]||y<=n){
			if (x<=top[u]&&(y>n||p[u][x]<eid[i][y])) q[++nQ]=p[u][x++];
			else q[++nQ]=eid[i][y++];
		}
		dfs(i,s+1);
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i){
		cin>>tmp[i].u>>tmp[i].v>>tmp[i].w;
	}
	sort(tmp+1,tmp+1+m,cmp);
	reduce_edges();
	for (int i=1;i<=k;++i){
		cin>>c[i];
		for (int x=1;x<=n;++x){
			cin>>e[++m].w;
			e[m].u=x;e[m].v=n+i;
		}
	}
	sort(e+1,e+1+m,cmp);
	for (int i=1;i<=m;++i){
		if (e[i].v<=n){
			p[0][++top[0]]=i;
		}
		else{
			int x=e[i].v-n;
			eid[x][++top[x]]=i;
		}
	}
	for (int i=1;i<=k;++i) top[i]=0;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
