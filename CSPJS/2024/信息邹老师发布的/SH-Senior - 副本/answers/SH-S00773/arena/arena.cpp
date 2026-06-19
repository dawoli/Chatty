#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define sizc(x) ((x).size())
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

constexpr int N = 1<<17;

int n,m,K;
ui a_[N],a[N];
int c[N];
bool D[N];
ui X[4];

ll f[N<<1][18],g[N<<1][18];

ll res[N];

void solve(){
	repn(i,4)cin>>X[i];
	repn(i,1<<K+1)rep(j,0,K)f[i][j]=g[i][j]=0;
	repn(i,1<<K)g[i|(1<<K)][0]=i+1;
	per(i,(1<<K)-1,1)g[i][0]=g[i<<1][0]+g[i<<1|1][0];
	repn(i,n)a[i]=a_[i]^X[i+1&3],a[i]=min(a[i],ui(K));
	repn(i,n){
		int x=i|(1<<K);
		f[x][a[i]]=i+1,g[x][0]=0;
		int k=0;while((1<<k)<=i)++k;
		while((x>>=1)>=(1<<K-k)){
			int lim=K-__lg(x),ls=x<<1,rs=x<<1|1; 
			rep(j,0,K)f[x][j]=g[x][j]=0;
			bool cl=0;
			if(!D[x]){
				repn(j,lim)cl|=f[ls][j]||g[ls][j];
				rep(j,lim,K)f[x][j]+=f[ls][j];
				rep(j,0,K)g[x][max(lim,j)]+=g[ls][j];
				if(cl)rep(j,0,K)f[x][j]+=f[rs][j],g[x][j]+=g[rs][j];
			}
			else{
				repn(j,lim)cl|=f[rs][j]||g[rs][j];
				rep(j,lim,K)f[x][j]+=f[rs][j];
				rep(j,0,K)g[x][max(lim,j)]+=g[rs][j];
				if(cl)rep(j,0,K)f[x][j]+=f[ls][j],g[x][j]+=g[ls][j];
			}
		}
		res[i]=0;
		rep(j,0,K)res[i]+=f[1<<K-k][j]+g[1<<K-k][j];
	}
	ll ans=0;
	rep(i,1,m)ans^=i*res[c[i]];
	cout<<ans<<'\n';
}

signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;while((1<<K)<n)++K;
	repn(i,n)cin>>a_[i];
	rep(i,1,m)cin>>c[i],--c[i];
	rep(i,1,K){
		repn(j,1<<K-i){
			char ch;cin>>ch;
			D[j|(1<<K-i)]=ch=='1';
		}
	}
	int T;cin>>T;
	while(T--)solve();
} 
