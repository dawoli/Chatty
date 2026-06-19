#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k,cnt,fa[12345],a[12345];
ll ans;
struct node{
	int u,v;
	ll w;
}G[1234567];
bool operator<(const node&x,const node&y){
	return x.w<y.w;
}
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(find(fa[u]));
}
void merge(int u,int v){
	int u1=find(u),v1=find(v);
	if(u1==v1)return;
	fa[u1]=v1;
	return;
}
void mst(){
	int cur=0;
	for(int i=1;i<=cnt;i++){
		if(cur==n-1)break;
		int nu=G[i].u,nv=G[i].v;
		if(find(nu)==find(nv))continue;
		merge(nu,nv);
		ans+=G[i].w;
		cur++;
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[++cnt]={u,v,w};
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1,x;i<=k;i++){
		cin>>x;
		int z=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]==0)z=j;
		}
		for(int j=1;j<=n;j++){
			if(j==z)continue;
			G[++cnt]={z,j,a[j]};
		}
	}
	sort(G+1,G+cnt+1);
	mst();
	cout<<ans<<'\n';
	return 0;
}
