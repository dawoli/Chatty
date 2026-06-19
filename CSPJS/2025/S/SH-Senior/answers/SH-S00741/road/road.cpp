#include<bits/stdc++.h>
#define N 10029
#define M 1000009
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge &b){
		return w<b.w;
	}
} e[M],f[N*10],g[N];
int fa[N],c[20],tot;
int find(int x){
	if(fa[x])return fa[x]=find(fa[x]);
	else return x;
}
bool merge(int x,int y){
	x=find(x);y=find(y);
	if(x^y)fa[x]=y;
	return x^y;
}
ll solve(int x){
	ll ret=0;memset(fa,0,sizeof(fa));
	for(int i=0;i<k;i++)if((x>>i)&1)ret+=c[i];
	for(int i=1,j=1;i<n||j<=m;){
		if(i<n&&(j>m||g[i].w<f[j].w)){
			if(merge(g[i].u,g[i].v))ret+=g[i].w;++i;
		}
		else{
			if((x>>f[j].u)&1){
				if(merge(f[j].u+n+1,f[j].v))ret+=f[j].w;
			}++j;
		}
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){cin>>e[i].u>>e[i].v>>e[i].w;};sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v))g[++tot]=e[i];
	}m=n*k;assert(tot==n-1);
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1,t=i*n+1;j<=n;j++,t++){
			cin>>f[t].w;f[t].u=i;f[t].v=j;
		}
	}sort(f+1,f+m+1);
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++)ans=min(ans,solve(i));
	cout<<ans<<"\n";
	return 0;
}
