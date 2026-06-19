#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n,mxn;
ll f[100009];
ll cost[10]={6,2,5,5,4,5,6,3,7,6};
void solve(){
	scanf("%lld",&n);
	if(n==0){
		printf("-1\n");
		return;
	}
	for(ll i=mxn+1;i<=n;i++){
		f[i]=1e9;
		for(ll k=0;k<=9;k++){
			if(i<cost[k]) continue;
			if(i-cost[k]==0&&k==0) continue;
			if(f[i-cost[k]]==-1) continue;
			ll res=f[i-cost[k]]*10+k;
			f[i]=min(f[i],res);
		}
		if(f[i]==1e9) f[i]=-1;
	}
	mxn=n;
	printf("%lld\n",f[n]);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&T);
	mxn=1;
	f[0]=0;f[1]=-1;
	while(T--) solve();
	return 0;
}
