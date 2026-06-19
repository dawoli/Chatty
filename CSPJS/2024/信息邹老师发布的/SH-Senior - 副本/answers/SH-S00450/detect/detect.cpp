#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll t,n,m,l,V,d[N],v[N],a[N],p[N],np[N];
bool st[N],nst[N];
ll read() {
	ll x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
void func(ll m,ll *p,bool *st) {
	for(ll i=1; i<=n; ++i) {
		ll j=lower_bound(p+1,p+m+1,d[i])-p;
		if(j>m) continue;
		for(; j<=m; ++j) {
			if(a[i]) {
				ll nv=v[i]*v[i]+2*a[i]*(p[j]-d[i]);
				if(nv<=0) break;
				if(nv>V*V) {
					st[i]=1;
					break;
				}
			} else if(v[i]>V) {
				st[i]=1;
				break;
			}
		}
	}
}
bool checkA0() {
	for(ll i=1; i<=n; ++i) if(a[i]) return 0;
	return 1;
}
void solveBF() {
	ll ans=0;
	for(ll i=0; i<1<<m; ++i) {
		ll k=0;
		for(ll j=0; j<m; ++j) if(i>>j&1) np[++k]=p[j+1];
		memset(nst,0,sizeof(nst));
		func(k,np,nst);
		bool flg=1;
		for(ll j=1; j<=n; ++j)
			if(st[j]!=nst[j]) {
				flg=0;
				break;
			}
		if(flg) ans=max(ans,m-k);
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	t=read();
	while(t--) {
		n=read(),m=read(),l=read(),V=read();
		for(ll i=1; i<=n; ++i) d[i]=read(),v[i]=read(),a[i]=read();
		for(ll i=1; i<=m; ++i) p[i]=read();
		memset(st,0,sizeof(st));
		func(m,p,st);
		ll ans=0;
		for(ll i=1; i<=n; ++i) ans+=st[i];
		cout<<ans<<" ";
		if(checkA0()) cout<<m-((ans)?1:0)<<"\n";
		else solveBF();
	}
	return 0;
}
