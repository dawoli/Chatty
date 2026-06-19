#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define MAXN 10005
#define MAXM 10000005
using namespace std;
typedef long long LL;
LL w0[MAXN][MAXN];
int adcity[MAXN][11];
int costad[11];
LL w[MAXN][MAXN],dis[MAXN];
LL ans;
bool vis[MAXN];
int n,m,k;
template<typename T,typename Q>
inline void minn(T & a,Q b){
	if(a>b)a=b;
}
namespace Solve0104{
	int *fa;
	int Find(int x){
		return fa[fa[x]]==fa[x]?fa[x]:fa[x]=Find(fa[x]);
	}
	bool Merge(int x,int y){
		x=Find(x),y=Find(y);
		if(x==y)return 0;
		fa[x]=y;
		return 1;
	}
	struct Edge{
		int u,v,w;
	};
	Edge *es;
	int cntk;
	inline bool cmp(const Edge & a,const Edge & b){
		return a.w<b.w;
	}
	int cntedge=0;
	inline void init(){
		fa=new int [MAXN];
		es=new Edge[MAXM];
		rep(i,1,n) fa[i]=i;
	}
	inline void ending(){
		delete []fa;
		delete []es;
	}
	inline void addedge(int u,int v,int w){
		es[++cntk].u=u;
		es[cntk].v=v;
		es[cntk].w=w;
	}
	inline LL work(){
		init();
		int a,b,c;
		rep(i,1,m) scanf("%d%d%d",&a,&b,&c),addedge(a,b,c),minn(w0[a][b],LL(c)),minn(w0[b][a],LL(c));
		std::sort(es+1,es+m+1,cmp);
		int cnt=0;LL ans=0;
		rep(i,1,m){
			if(Merge(es[i].u, es[i].v)) cnt++, ans+=es[i].w;
			if(cnt==n) goto Ending;
		}
		Ending:
			ending();
		return ans;
	}
}

LL Prim(int situa){
	rep(i,1,n) rep(j,i+1,n) w[i][j]=w0[i][j];
	LL ans1=0;
	rep(i,0,k-1) if((situa>>i) & 1){
		ans1+=costad[i];
	}
	if(ans1>=ans&&ans!=-1) return ans;
	rep(i,0,k-1) if((situa>>i) & 1)
		rep(j,1,n){
			rep(k114514,j+1,n) if(w[j][k114514]>adcity[j][i]+adcity[k114514][i])w[j][k114514]=adcity[j][i]+adcity[k114514][i];
		}
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	rep(i,1,n){
		LL minj,mindis=(1ll<<60);
		rep(j,1,n) if(!vis[j]&&dis[j]!=-1) if(dis[j]<mindis) minj=j,mindis=dis[j];
		ans1+=mindis;
		rep(j,1,minj-1) if(dis[j]>w[j][minj]) dis[j]=w[j][minj];
		rep(j,minj+1,n) if(dis[j]>w[minj][j]) dis[j]=w[minj][j];
		vis[minj]=1;
		if(ans1>ans) return ans1;
	}
	return minn(ans,ans1),ans1;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(w0,0x7f,sizeof(w0));
	
	ans=Solve0104::work();
	rep(i,0,k-1) {
		scanf("%d",&costad[i]);
		rep(j,1,n) scanf("%d",&adcity[j][i]);
	}
	rep(i,1,(1<<k)-1)
		Prim(i);
	printf("%lld",ans);
	return 0;
}
