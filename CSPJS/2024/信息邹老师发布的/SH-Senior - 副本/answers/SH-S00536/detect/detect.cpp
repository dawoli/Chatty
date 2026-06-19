#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+9;
const ld ERR=1e-10;
ll n,m,L,V,d[N],a[N],v[N],p[N];
ll cnt,nP[N];//newp
void solveBF(ll nFast){
	ll res=0;
	ll ans=1e18;
	for(ll i=0;i<(1<<m);i++) {
		cnt=0;
		for(int j=1;j<=m;j++)
			if(i>>(j-1)&1)
				nP[++cnt]=p[j];
		res=0;
		for(int j=1;j<=n;j++){
			ll pos=nP[cnt];
			if(a[j]<0){
				ll lb=upper_bound(nP+1,nP+1+cnt,d[j])-nP;
				if(lb>cnt) lb=cnt;
				if(nP[lb-1]==d[j]) lb--;
				pos=nP[lb];
			}
			ld num=v[j]*v[j]*1.0+2.0*a[j]*(pos-d[j]);
			ld Spd=sqrt(max(num,(ld)0.00));
			if(pos<d[j]) Spd=0;
			if(Spd-V>ERR) res++;
		}
		if(res>=nFast) ans=min(ans,cnt);
	}
	cout<<m-ans<<endl;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
		ll res=0;
		for(int i=1;i<=n;i++){
			ll pos=p[m];
			if(a[i]<0){
				ll lb=upper_bound(p+1,p+1+m,d[i])-p;
				if(lb>m) lb=m;
				if(p[lb-1]==d[i]) lb--;
				pos=p[lb];
			}
			ld num=v[i]*v[i]*1.0+2.0*a[i]*(pos-d[i]);
			ld Spd=sqrt(max(num,(ld)0.00));
			if(pos<d[i]) Spd=0;
			if(Spd-V>ERR) res++;
		}
		cout<<res<<" ";
		if(n<=20) solveBF(res);
		else {
			if(res==0) cout<<m<<endl;
			else cout<<m-1<<endl; 
		}
	}
	return 0;
}
