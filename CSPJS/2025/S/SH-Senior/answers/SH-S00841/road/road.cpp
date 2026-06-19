#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
const long long N=1e4+100;
struct Edge{
	long long t,w;
};
std::vector<Edge> es[N];
long long n,m,k;
long long U,V,W;
long long c[N];
long long a[20][N];
bool flag=1;
long long d[N];
long long fa[N];
long long ans;
bool vst[N];
long long p[20];
long long cnt;
long long Ans=1e17;
inline void Prim(){
	memset(d,0x7f,sizeof(d));
	memset(vst,0,sizeof(vst));
	d[1]=0;
	for(long long i=1;i<=n;i++){
		long long MIN=1e15,u;
		for(long long j=1;j<=n;j++){
			if(d[j]<MIN&&!vst[j]){
				MIN=d[j];
				u=j;
			}
		}
//		prlong longf("u=%lld,MIN=%lld\n",u,MIN);
		ans+=MIN;
		vst[u]=1;
		for(long long j=0;j<es[u].size();j++){
			long long nw=es[u][j].t;
			d[nw]=std::min(d[nw],es[u][j].w);
//			prlong longf("d[%lld]=%lld\n",nw,d[nw]);
		}
	}
//	prlong longf("ans=%lld\n",ans);
	Ans=std::min(ans,Ans);
}
void calc(){
//	prlong longf("\n\n");
//	for(long long i=1;i<=cnt;i++){
//		prlong longf("p[%lld]=%lld\n",i,p[i]);
//	}
	ans=0;
	for(long long i=1;i<=cnt;i++){
		while(es[n+i].size()!=0) es[n+i].pop_back();
		ans+=c[p[i]];
		for(long long j=1;j<=n;j++){
			es[n+i].push_back((Edge){j,a[p[i]][j]});
			es[j].push_back((Edge){n+i,a[p[i]][j]});
		}
	}
	n+=cnt;
	Prim();
	n-=cnt;
}
void dfs(long long x){
	if(x==k+1){
		calc();
		return;
	}
	p[++cnt]=x;
	dfs(x+1);
	cnt--;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=1;i<=m;i++){
		scanf("%d%d%d",&U,&V,&W);
		es[U].push_back((Edge){V,W});
		es[V].push_back((Edge){U,W});
	}
	for(long long j=1;j<=k;j++){
		scanf("%d",c+j);
		if(c[j]!=0) flag=0;
		for(long long i=1;i<=n;i++){
			scanf("%d",&a[j][i]);
		}
	}
	if(k==0) Prim();
	else dfs(1);
	printf("%lld\n",Ans);
	return 0;
}
