#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define Rep(i,l,r) for(int i=(l);i>=(r);--i)
#define int long long
#define INF 1e18
#define gc getchar()
using namespace std;
namespace fastIO{
	int read(){
		int x=0,f=1;
		char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=gc;
		}
		return x*f;
	}
}
using namespace fastIO;
int p[10109][1025];
int c[19];
int a[19][10009];
int ans[1025];
int n,m,k,id,ru,rv; 
struct edge{
	int u,v,w;
	bool operator < (const edge &o) const{
		return w<o.w;
	}
} g[1000009],e[110009]; 
int getrt(int x,int ly){
	if(p[x][ly]==x) return x;
	return p[x][ly]=getrt(p[x][ly],ly);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int L=(1<<k);
	rep(i,1,m){
		g[i].u=read(),g[i].v=read(),g[i].w=read();
	}
	rep(i,1,k){
		c[i]=read();
		rep(j,1,n){
			a[i][j]=read();
		}
	}
	sort(g+1,g+m+1);
	rep(i,1,n+k){
		rep(j,0,L){
			p[i][j]=i;
		}
	}
	rep(i,1,m){
		ru=getrt(g[i].u,L),rv=getrt(g[i].v,L);
		if(ru==rv) continue;
		p[ru][L]=rv;
		e[++id]=g[i];
	}
	rep(i,0,L-1){
		rep(msk,1,k){
			if(i&(1<<(msk-1))) ans[i]+=c[msk];
		}
	}
	rep(i,1,k){
		rep(j,1,n){
			e[++id]={n+i,j,a[i][j]};
		}
	}
	sort(e+1,e+id+1);
	rep(i,1,id){
		int nd=0;
		if(e[i].u>n) nd=e[i].u-n;
		rep(msk,0,L-1){
			if(nd>0&&(!(msk&(1<<(nd-1))))) continue;
			ru=getrt(e[i].u,msk),rv=getrt(e[i].v,msk);
			if(ru==rv) continue;
			p[ru][msk]=rv;
			ans[msk]+=e[i].w;
		}
	}
	int mn=INF;
	rep(i,0,L-1)  mn=min(mn,ans[i]);
	cout<<mn<<endl;	
	return 0;
}

