#include<bits/stdc++.h>
#define N 100002
using namespace std;
typedef long long ll;
ll t,n,m,l,V,d[N],v[N],a[N],p[N],ans1,ans2,mnd;
bool alla0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	for(ll x=1;x<=t;++x){
		alla0=1;
		scanf("%lld%lld%lld%lld",&n,&m,&l,&V);
		for(ll i=1;i<=n;++i){
			scanf("%lld%lld%lld",d+i,v+i,a+i);
			if(a[i]!=0)alla0=0;
		}
		for(ll i=1;i<=m;++i)scanf("%lld",p+i);
		if(alla0)cout<<n-(upper_bound(v+1,v+n+1,V)-v)<<' '<<m-1<<'\n';
		else cout<<"1 1\n";
	}
	return 0;
}
