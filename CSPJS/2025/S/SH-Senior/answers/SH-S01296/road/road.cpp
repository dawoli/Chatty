#include<algorithm>
#include<utility>
#include<cstdio>
using namespace std;
typedef long long LL;
const int SIZI=(1<<16)-1;
char bufi[SIZI];	char *Si=bufi,*Ti=bufi;
#define load() (Ti=bufi+fread(Si=bufi,1,SIZI,stdin))
#define gc() ((__builtin_expect(Si==Ti,false)&&(load(),Si==Ti))?EOF:(*Si++))
inline int read(){
	int x=0,f=1;	char ch=gc();
	for(;(ch<'0')||(ch>'9');ch=gc())
		(ch=='-')&&(f=-1);
	for(;(ch>='0')&&(ch<='9');ch=gc())
		x=x*10+ch-'0';
	return x*f;
}
typedef pair<int,int> PII;
const int N=10020,M=1000010,K=10;
int n,m,k;	LL res;
struct Edge{
	int u,v,w;
	bool operator<(Edge e){return w<e.w;}
};
Edge es[M],e[1<<K][N],ee[N],te[N+N];
PII val[K][N];	int fa[N];
inline int find(int x){
	return (fa[x]!=x)?(fa[x]=find(fa[x])):x;
}
inline LL calc(Edge es[],int m,Edge ne[]){
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	LL ans=0;	int tot=0;
	for(int i=0,u,v;i<m;i++)
		if((u=find(es[i].u))!=(v=find(es[i].v))){
			ans+=es[i].w;	fa[u]=v;	ne[tot++]=es[i];
		}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();	m=read();	k=read();	res=1e18;
	for(int i=0;i<m;i++){
		es[i].u=read();	es[i].v=read();	es[i].w=read();
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++)
			val[i][j]=PII(read(),j);
		sort(val[i]+1,val[i]+n+1);
	}
	sort(es,es+m);	res=min(res,calc(es,m,e[0]));
	for(int i=1;i<(1<<k);i++){
		int low=__builtin_ctz(i&(-i)),j=i^(1<<low);
		int cnt=__builtin_popcount(i),tot=0;
		for(int u=1;u<=n;u++)
			ee[tot++]=(Edge){n+low+1,val[low][u].second,val[low][u].first};
		merge(ee,ee+tot,e[j],e[j]+n+cnt-2,te);
		tot+=n+cnt-2;	LL ans=0;
		for(int u=0;u<k;u++)
			((i>>u)&1)&&(ans+=val[u][0].first);
		res=min(res,ans+=calc(te,tot,e[i]));
	}
	printf("%lld\n",res);
	return 0;
}
