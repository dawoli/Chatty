#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9,M=1e6+9,K=19;
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
#define ll long long
int n,m,k,fa[N],a[K],h[K];
int get(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
struct love{int u,v,w;}g[M],e[K][N];
bool cmp(const love&a,const love&b){return a.w<b.w;}
ll sol(int p){
	ll ans=0;
	for(int i=0;i<k;i++)if(p&(1<<i)) ans+=a[i+1];
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int cnt=0;
	for(int i=0;i<=k;i++) h[i]=1;
	while(cnt<n+__builtin_popcount(p)-1){
		int mn=1e9,mnp=0;
		if(h[0]<n) mn=e[0][h[0]].w;
		for(int i=0;i<k;i++)if(p&(1<<i)){
			if(h[i+1]>n) continue;
			int wn=e[i+1][h[i+1]].w;
			if(wn<mn) mn=wn,mnp=i+1;
		}
		love cur=e[mnp][h[mnp]];
		int u=cur.u,v=cur.v,w=cur.w;
		h[mnp]++;
		int fx=get(u),fy=get(v);
		if(fx==fy) continue;
		fa[fx]=fy;
		cnt++;
		ans+=w;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) g[i].u=read(),g[i].v=read(),g[i].w=read();
	sort(g+1,g+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		int fx=get(u),fy=get(v);
		if(fx==fy) continue;
		fa[fx]=fy;
		cnt++;
		e[0][cnt]=(love){u,v,w};
		if(cnt==n-1) break;
	}
	sort(e[0]+1,e[0]+n,cmp);
	for(int i=1;i<=k;i++){
		a[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			e[i][j]=(love){n+i,j,x};
		}
	}
	for(int i=1;i<=k;i++) sort(e[i]+1,e[i]+n+1,cmp);
	ll ans=1e18;
	for(int p=0;p<(1<<k);p++) ans=min(ans,sol(p));
	cout<<ans<<endl;
	return 0;
}
