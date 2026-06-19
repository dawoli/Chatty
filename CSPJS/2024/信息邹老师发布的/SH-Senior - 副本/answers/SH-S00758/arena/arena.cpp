#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
#define int ll
#define debug(x) (cerr<<#x": "<<x<<endl)
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
// #define rand(x,y) uniform_int_distribution<int>(x,y)(rng)

bool __ST;

const int N=131111;
int n,m,araw[N],a[N],c[N],K;

#define ls (x<<1)
#define rs (x<<1|1)
bool d[N<<1];int L[N<<1],R[N<<1],H[N<<1];
void build(int x,int l,int r,int h){
	L[x]=l,R[x]=r,H[x]=h;
	int mid=(l+r)>>1;
	if(l==r) return;
	build(ls,l,mid,h-1),build(rs,mid+1,r,h-1);
}
int KK(int x){return x==1?0:__lg(x-1)+1;}
namespace S{
	int f[N<<1][19];
	void pu(int x){
		int j;
		bool v;
		if(d[x]==0){
			v=f[ls][18];
			for(j=0;j<H[x];j++) if(f[ls][j]!=0) v=1;
			for(j=0;j<=17;j++){
				f[x][j]=0;
				if(j>=H[x]) f[x][j]=f[ls][j];
				if(v) f[x][j]+=f[rs][j];
			}
			f[x][18]=f[ls][18]+(v?f[rs][18]:0);
		}
		else{
			v=f[rs][18];
			for(j=0;j<H[x];j++) if(f[rs][j]!=0) v=1;
			for(j=0;j<=17;j++){
				f[x][j]=0;
				if(j>=H[x]) f[x][j]=f[rs][j];
				if(v) f[x][j]+=f[ls][j];
			}
			f[x][18]=f[rs][18]+(v?f[ls][18]:0);
		}
	}
	void upd(int x,int d){
		if(L[x]==R[x]){
			f[x][18]=0;
			f[x][a[d]]=d;
			return;
		}
		if(d<=R[ls]) upd(ls,d);else upd(rs,d);
		pu(x);
	}
	void init(int x){
		if(L[x]==R[x]){
			for(int j=0;j<=17;j++) f[x][j]=0;
			f[x][18]=x-(1<<K)+1;
			return;
		}
		init(ls),init(rs);pu(x);
	}
	int ans[N];
	void work(){
		int i;
		for(i=1;i<=n;i++) a[i]=min(a[i],K);
		init(1);
		for(i=1;i<=(1<<K);i++){
			upd(1,i);
			int x=1;while(R[x]>(1<<KK(i))) x<<=1;
			ans[i]=0;for(int j=0;j<=18;j++) ans[i]+=f[x][j];
			// if(i==3){
			// 	debug(f[4][1]);
			// 	debug(f[2][1]);
			// 	debug(f[5][18]);
			// 	debug(d[2]);
			// }
		}
		// for(i=1;i<=8;i++) cerr<<ans[i]<<' ';cerr<<endl;
		int __=0;for(i=1;i<=m;i++) __^=i*ans[c[i]];
		cout<<__<<'\n';
	}
}

bool __ED;
signed main(){
	// cerr<<fabs(&__ST-&__ED)/(1<<20)<<"MB"<<endl;
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>araw[i];
	for(i=1;i<=m;i++) cin>>c[i];
	for(K=0;;K++) if((1<<K)>=n) break;
	build(1,1,1<<K,K);
	string s0[20],ss=" ";for(i=1;i<=K;i++) cin>>s0[i];
	for(i=K;i>=1;i--) ss+=s0[i];
	for(i=1;i<(1<<K);i++) d[i]=ss[i]-'0';
	int _;cin>>_;while(_--){
		int x[4];cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(i=1;i<=n;i++) a[i]=araw[i]^x[i&3];
		S::work();
	}
	// cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
	return 0;
}
