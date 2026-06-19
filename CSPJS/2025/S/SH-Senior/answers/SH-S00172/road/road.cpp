#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
	int u,v;
	long long w;
	friend bool operator < (Edge a,Edge b){
		return a.w<b.w;
	}
}a[1000001],b[10001],c[210001];
int fa[10021]={},sz[10021]={},cnt=0;
long long cost[11]={},val[11][10001]={};
bool used[11]={};
void init(){
	for(int i=1;i<=n+10;i++)fa[i]=i,sz[i]=1; 
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return 0;
	if(sz[fx]>sz[fy])swap(fx,fy);
	sz[fy]=sz[fx]+1;
	fa[fx]=fy;
	return 1;
}
long long ans=0ll,tans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	init();
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		int u=a[i].u,v=a[i].v;
		if(merge(u,v)){
			b[++cnt]=a[i];
			ans+=a[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cost[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&val[i][j]);
		}
	}
	for(int i=1;i<=(1<<k)-1;i++){
		tans=0ll;
		for(int j=1;j<=n-1;j++)c[j]=b[j];
		int ccc=0,idx=n-1;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				ccc++;
				used[j]=1;
				tans+=cost[j];
				for(int _=1;_<=n;_++){
					c[++idx].u=n+j;
					c[idx].v=_;
					c[idx].w=val[j][_];
				}
			}
			else used[j]=0;
		}
		int lim=ccc+(n-1),vercount=0;
		sort(c+1,c+idx+1);
		init();
		for(int i=1;i<=idx;i++){
			if(vercount==lim)break;
			int u=c[i].u,v=c[i].v;
			if(merge(u,v)){
				tans+=c[i].w;
				vercount++;
			}
		}
		ans=min(ans,tans);
	}
	printf("%lld",ans);
	return 0;
}
