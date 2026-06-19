#include<bits/stdc++.h>
#define N 100005
#define DEBUG 0
#define LSH 0
using namespace std;
int n,m,nn,L,V,p[N],c[2000005],nt,trs[N],f[N],bit[N];
map<int,int>mp;
bitset<N>ok;
struct Itv{int l,r,op;Itv(int ll=0,int rr=0){l=ll,r=rr;}}tt[N],t[N];
bool operator<(const Itv &x,const Itv &y){
	return x.l<y.l||(x.l==y.l&&x.r>y.r);
}
void adi(int l,int r){
	l=max(l,0),r=min(r,L);
	if(l<=r){tt[++nt]=Itv(l,r);
		if(LSH)mp[l]=mp[r]=1;
	}
}
void asrt(bool flg){
	if(!flg)cerr<<"!\n";
}
void upd(int x,int val){while(x<=nt+1)bit[x]=min(bit[x],val),x+=x&-x;}
int qr(int x){int r=m;while(x)r=min(bit[x],r),x-=x&-x;return r;}
void ssolve(){
	stable_sort(t+1,t+1+nt);int _=1;
	for(int i=2;i<=nt;i++){
		while(t[i].r<t[_].r)--_;
		t[++_]=t[i];
	}
	nt=_;
	if(DEBUG){
	for(int i=1;i<=nt;i++)cerr<<t[i].l<<' '<<t[i].r<<'\n';
	for(int i=1;i<=m;i++)cerr<<p[i]<<' ';
	cerr<<'\n';
	cerr<<'\n';
	}
	for(int i=1,l=1,r=0;i<=m;i++){
		while(r<nt&&t[r+1].l<=p[i])++r;
		while(l<=nt&&t[l].r<p[i])++l;
		if(DEBUG){
		cerr<<l<<' '<<r<<' '<<t[l].l<<' '<<t[l].r<<' '
		<<t[r].l<<' '<<t[r].r<<' '<<p[i]<<'\n';
		}
		if(l<=r){
			if(!ok[r])trs[r]=l,ok[r]=1;
			else trs[r]=min(trs[r],l);
		}
	}
	for(int i=1;i<=nt;i++)bit[i]=f[i]=m;
	bit[nt+1]=0,f[0]=0;
	for(int i=1;i<=nt;i++){
		if(ok[i])f[i]=qr(nt-(trs[i]-1)+1)+1;
		if(DEBUG)cerr<<i<<' '<<f[i]<<' '<<trs[i]<<'\n';
		upd(nt-i+1,f[i]);
	}
	cout<<m-f[nt]<<'\n';
	ok.reset();
}
void solve(){
	cin>>n>>m>>L>>V;
	for(int i=1,d,v,a;i<=n;i++){
		cin>>d>>v>>a;
		if(a<0){
			if(v>V)adi(d,d+(v*v-V*V-1)/(-2*a));
		}
		if(a==0){
			if(v>V)adi(d,L);
		}
		if(a>0){
			if(v>V)adi(d,L);
			if(v==V)adi(d+1,L);
			if(v<V)adi(d+(V*V-v*v)/(2*a)+1,L);
		}
	}
	for(int i=1;i<=m;i++)cin>>p[i];
	if(LSH){
		for(int i=1;i<=m;i++)mp[p[i]]=1;
		for(auto &[v,i]:mp)i=++nn;
		for(int i=1;i<=nt;i++)tt[i].l=mp[tt[i].l],tt[i].r=mp[tt[i].r];
		for(int i=1;i<=m;i++)p[i]=mp[p[i]];
		L=nn;
	}
	
	// for(int i=1;i<=nt;i++)cerr<<t[i].l<<' '<<t[i].r<<'\n';
	for(int i=1;i<=m;i++)++c[p[i]+1];
	for(int i=1;i<=L+1;i++)c[i]+=c[i-1];
	int ans1=0;int _=0;
	for(int i=1;i<=nt;i++)
		if(c[tt[i].r+1]-c[tt[i].l])++ans1,t[++_]=tt[i];
	nt=_;
	cout<<ans1<<' ';
	if(ans1)ssolve();else cout<<m<<'\n';
	for(int i=L+1;i>=1;i--)c[i]=0;
	mp.clear(),
	nn=nt=0;
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;cin>>T;
	while(T--)solve();
	return 0;
}