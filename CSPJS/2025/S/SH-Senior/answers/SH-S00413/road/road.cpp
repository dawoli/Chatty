#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10001],fa[10001],sz[10001],bs=1,u,v,w,zrp;
long long ans;
struct Edge{
	int a,b,d;
} ed[1100001];
bool cmp(const Edge &a,const Edge &b){
	return a.d<b.d;
}
int frt(int x){
	int y=x;
	while(y!=fa[y]) y=fa[y];
	while(x!=fa[x]){
		int z=fa[x];
		fa[x]=y;
		x=z;
	}
	return x;
}
bool unn(int x,int y){
	x=frt(x);
	y=frt(y);
	if(x==y) return 1;
	if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ed[i]=(Edge){u,v,w};
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=0;i<k;i++){
		scanf("%d",&zrp);
		for(int j=1;j<=n;j++){
			scanf("%d",c+j);
			if(c[j]==0) zrp=j;
		}
		for(int j=1;j<=n;j++) ed[m+i*n+j]=(Edge){zrp,j,c[j]};
	}
	sort(ed+1,ed+m+k*n+1,cmp);
	for(int i=1;bs<n;i++){
		if(unn(ed[i].a,ed[i].b)) continue;
		ans+=ed[i].d;
		bs++;
	}
	cout<<ans;
	return 0;
}
