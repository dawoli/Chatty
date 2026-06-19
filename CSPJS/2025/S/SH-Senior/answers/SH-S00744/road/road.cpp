#include<bits/stdc++.h>
using namespace std;
const int maxk=10;
const int maxn=1e4+1;
const int maxm=1e6+1;
struct edge{
	int u,v,w;
}e[maxm+maxn*maxk];
int n,m,k,a[maxk][maxn],c[maxk],ans=0;bool is=true;
int fa[maxn+maxk],u,v,w,fau,fav,cnt;
inline bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void kruskal(){
	sort(e,e+cnt,cmp);int ed=0;
	for(int i=0;i<n+k;i++) fa[i]=i;
	for(int i=0;i<cnt;i++){
		if(ed>=n+k-1) break;
		u=e[i].u,v=e[i].v,fau=get(u),fav=get(v);
		if(fau==fav) continue;
		ans+=e[i].w;fa[fau]=fav;ed++;
	}
	printf("%d",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		e[i].u--;e[i].v--;
	}
	cnt=m;
	for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		if(c[i]>0) is=false;
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			e[cnt++]=(edge){n+i,j,a[i][j]};
		}
	}
	if(is){
		kruskal();
	}
	return 0;
}
