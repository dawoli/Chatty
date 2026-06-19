#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005,M=1000005,K=11;
const ll INF=1e13;
int n,m,k,Mp,c[K],id[N+K],a[K][N];
ll ans=INF;
bool rd[K];
struct Edge{int u,v,w;}e[M],ee[N*K];
bool cmp(const Edge&x,const Edge&y){return x.w<y.w;}
int fd(int x){return(id[x]==x?x:id[x]=fd(id[x]));}
ll Kruskal(){
	int mm=0,nn=0;
	for(int i=1;i<=k;++i)if(rd[i]){
		++nn;
		for(int j=1;j<=n;++j)if(a[i][j]<Mp-c[i])
			++mm,ee[mm].u=n+nn,ee[mm].v=j,ee[mm].w=a[i][j];
	}sort(ee+1,ee+mm+1,cmp);
	for(int i=1;i<=n+nn;++i)id[i]=i;
	int L=1,R=1,cnt=0;
	ll p=0;
	while(cnt<n+nn-1){
		if(R>mm||e[L].w<ee[R].w){
			int fu=fd(e[L].u),fv=fd(e[L].v);
			if(fu!=fv)id[fu]=fv,p+=(ll)e[L].w,++cnt;
			++L;
		}else{
			int fu=fd(ee[R].u),fv=fd(ee[R].v);
			if(fu!=fv)id[fu]=fv,p+=(ll)ee[R].w,++cnt;
			++R;
		}
	}return p;
}
void recursion(int now,ll price){
	if(now>k){ans=min(ans,price+Kruskal());return;}
	rd[now]=1,recursion(now+1,price+c[now]);
	rd[now]=0,recursion(now+1,price);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),Mp=max(Mp,e[i].w);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
	}recursion(1,0ll);
	printf("%lld",ans);
	return 0;
}
