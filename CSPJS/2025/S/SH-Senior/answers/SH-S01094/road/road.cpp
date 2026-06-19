#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10804
#define M 1400002
#define K 12
ll readint(){
	static char c;
	static ll r;r=0;
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58)r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r;
}
bool mbe;
int n,m,k,t[N],vcnt,ecnt;ll a,w[K],ans,sum;bool s[M];
struct edge{int u,v;ll w;}e[M],l[1031][N],r[N<<1],L[K][N];int c[1031];
bool cmp(const edge&a,const edge&b){return a.w<b.w;}
int pa[N];
int find(int p){return pa[p]==p?p:pa[p]=find(pa[p]);}
ll kruskal(int n,int m,int *id,edge *e,bool *mk){
	for(int i=1;i<=n;++i)pa[id[i]]=id[i];
//	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i)mk[i]=0;
	int a,b,cnt=0;ll res=0;
	for(int i=1;i<=m;++i){
		a=find(e[i].u),b=find(e[i].v);
		if(a!=b)++cnt,pa[a]=b,mk[i]=1,res+=e[i].w;
		if(cnt==n-1)break;
	}
	return res;
}
bool med;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=readint(),m=readint(),k=readint();
	for(int i=1;i<=m;++i)e[i].u=readint(),e[i].v=readint(),e[i].w=readint();
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<k;++i){
		w[i]=readint();
		for(int j=1;j<=n;++j)a=readint(),L[i][j]={j,n+i+1,a};
		sort(L[i]+1,L[i]+n+1,cmp);
	}
	for(int i=1;i<=n;++i)t[i]=i;
	ans=kruskal(n,m,t,e,s);
	for(int i=1;i<=m;++i)if(s[i])l[0][++c[0]]=e[i];
	for(int b=1,d,g;b<(1<<k);++b){
		for(g=0;g<k;++g)if((1<<g)==(b&(-b)))break;
		d=b-(b&(-b));ecnt=0;
		int le=1,re=1;
		for(int o=1;o<=n+c[d];++o){
			if(re>n||(le<=c[d]&&l[d][le].w<L[g][re].w))r[++ecnt]=l[d][le],++le;
			else r[++ecnt]=L[g][re],++re;
		}
		vcnt=0;sum=0;
		for(int i=1;i<=n;++i)t[++vcnt]=i;
		for(int i=0;i<k;++i)if((b>>i)&1)t[++vcnt]=n+i+1,sum+=w[i];
		sum+=kruskal(vcnt,ecnt,t,r,s);
		for(int i=1;i<=ecnt;++i)if(s[i])l[b][++c[b]]=r[i];
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

