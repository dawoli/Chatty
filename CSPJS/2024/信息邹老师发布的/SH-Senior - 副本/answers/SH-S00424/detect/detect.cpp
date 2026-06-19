#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,L,V,d[100010],v[100010],a[100010],x,ans,maxm;
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0,maxm=-1;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++){
			scanf("%lld",&x);
			maxm=max(maxm,x);
		}
		for(int i=1;i<=n;i++)
			if(d[i]<=maxm&&v[i]>V)
				ans++;
		printf("%lld %lld\n",ans,m-min(1LL,ans));
	}
	return 0;
} 
