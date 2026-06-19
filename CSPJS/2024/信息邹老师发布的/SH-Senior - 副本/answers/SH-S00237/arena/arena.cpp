#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
const ll K=19;
ll T,n,m,k,lg2[N],apre[N],a[N],t[4],mxdep;
bool d[K][N],chk;
char ch;
vector<vector<ll>> f[K];
vector<ll> zr;
struct Interval{
	ll l,r,mn;
} g[K][N];
struct Query{
	ll c,id;
} q[N];
bool cmp(const Query&a,const Query&b){
	return a.c<b.c;
}
void pushup(ll dep,ll i){
	f[dep][i].clear();
	g[dep][i]=(Interval){i+1,i,0};
	if(d[dep][i]==0){
		bool ok=0;
		for(ll j=0;j<f[dep-1][i*2-1].size();j++){
			ll cur=f[dep-1][i*2-1][j];
			if(a[cur]>=dep)
			    f[dep][i].push_back(cur);
			else ok=1;
		}
		if(g[dep-1][i*2-1].l<=g[dep-1][i*2-1].r&&g[dep-1][i*2-1].mn<dep)
		    ok=1;
		if(ok){
			for(ll j=0;j<f[dep-1][i*2].size();j++)
			    f[dep][i].push_back(f[dep-1][i*2][j]);
			if(g[dep-1][i*2-1].l>g[dep-1][i*2-1].r)
			    g[dep][i]=g[dep-1][i*2];
			else if(g[dep-1][i*2].l>g[dep-1][i*2].r){
				g[dep][i]=g[dep-1][i*2-1];
				g[dep][i].mn=max(g[dep][i].mn,dep);
			}else{
				g[dep][i].l=g[dep-1][i*2-1].l;
				g[dep][i].r=g[dep-1][i*2].r;
				g[dep][i].mn=min(max(g[dep-1][i*2-1].mn,dep),g[dep-1][i*2].mn);
			}
		}else{
			g[dep][i]=g[dep-1][i*2-1];
			g[dep][i].mn=max(g[dep][i].mn,dep);
		}
	}else{
		bool ok=0;
		for(ll j=0;j<f[dep-1][i*2].size();j++){
			ll cur=f[dep-1][i*2][j];
			if(a[cur]>=dep)
			    f[dep][i].push_back(cur);
			else ok=1;
		}
		if(g[dep-1][i*2].l<=g[dep-1][i*2].r&&g[dep-1][i*2].mn<dep)
		    ok=1;
		if(ok){
			for(ll j=0;j<f[dep-1][i*2-1].size();j++)
			    f[dep][i].push_back(f[dep-1][i*2-1][j]);
			if(g[dep-1][i*2].l>g[dep-1][i*2].r)
			    g[dep][i]=g[dep-1][i*2-1];
			else if(g[dep-1][i*2-1].l>g[dep-1][i*2-1].r){
				g[dep][i]=g[dep-1][i*2];
				g[dep][i].mn=max(g[dep][i].mn,dep);
			}else{
				g[dep][i].l=g[dep-1][i*2-1].l;
				g[dep][i].r=g[dep-1][i*2].r;
				g[dep][i].mn=min(max(g[dep-1][i*2].mn,dep),g[dep-1][i*2-1].mn);
			}
		}else{
			g[dep][i]=g[dep-1][i*2];
			g[dep][i].mn=max(g[dep][i].mn,dep);
		}
	}
}
void change(ll dep,ll l,ll r){
	for(ll i=l;i<=r;i++)
	    pushup(dep,i);
	if(dep==mxdep)return;
	change(dep+1,(l+1)/2,(r+1)/2);
}
ll calc(ll l,ll r){
	if(l>r)return 0;
	return (r-l+1)*(l+r)/2;
}
void solve(){
	for(ll i=0;i<=3;i++)
	    scanf("%lld",&t[i]);
	for(ll i=1;i<=n;i++)
	    a[i]=apre[i]^t[i%4];
	for(ll i=1;i<=(1ll<<lg2[n]);i++){
		f[0][i].clear();
		g[0][i]=(Interval){i,i,0};
	}
	ll ans=0;
	for(ll i=1;i<=m;i++){
		if(q[i-1].c<q[i].c){
		    for(ll j=q[i-1].c+1;j<=q[i].c;j++){
		    	f[0][j].clear();
		    	f[0][j].push_back(j);
		        g[0][j]=(Interval){j,j-1,0};
		    }
		    mxdep=lg2[q[i].c];
		    if(lg2[q[i].c]>lg2[q[i-1].c]&&mxdep)
		        change(1,(q[i-1].c+1+1)/2,(1ll<<(mxdep-1)));
		    else if(mxdep)change(1,(q[i-1].c+1+1)/2,(q[i].c+1)/2);
		}
		ll sum=0;
		for(ll j=0;j<f[mxdep][1].size();j++)
		    sum+=f[mxdep][1][j];
		sum+=calc(g[mxdep][1].l,g[mxdep][1].r);
		ans=ans^(sum*q[i].id);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
	    scanf("%lld",&apre[i]);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&q[i].c);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	for(ll i=1;i<=n;i++)
	    lg2[i]=ceil(log(i)/log(2));
	k=lg2[n];
	for(ll i=1;i<=k;i++){
		ch=getchar();
		while(!(ch=='0'||ch=='1'))
		    ch=getchar();
		for(ll j=1;j<=(1ll<<(k-i));j++)
		    d[i][j]=ch-'0',ch=getchar();
	}
	zr.clear();
	for(ll i=k;i>=0;i--)
	    for(ll j=1;j<=(1ll<<i)+1;j++)
	        f[k-i].push_back(zr);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
