#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,fa[20005],cnt,si[20005];
long long ans;
struct node{
	int u,v,w;
}ed[2000005];
bool cmp(node t1,node t2){
	return t1.w<t2.w;
}
int find(int p){
	if(fa[p]==p)return p;
	fa[p]=find(fa[p]);
	si[fa[p]]++;
	return fa[p];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			m++;
			ed[m].u=j;
			ed[m].v=n+i;
			ed[m].w=x;
		}
	}
	n+=k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		si[i]=1;
	}
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=m&&cnt<n;i++){
		x=ed[i].u;
		y=ed[i].v;
		z=ed[i].w;
		int fx=find(x);
		int fy=find(y);
		if(fx==fy)continue;
		if(si[fx]>si[fy])fa[fx]=fy;
		else fa[fy]=fx;
		ans+=z;
		cnt++;
	}
	printf("%lld",ans);
	return 0;
}
