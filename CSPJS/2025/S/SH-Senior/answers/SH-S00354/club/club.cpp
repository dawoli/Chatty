#include<bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long ll;
ll n,a[N][3],mx[N][2],mxid[N];
multiset<ll> se[3];
void input(){
	scanf("%lld",&n);
	for(ll j=0;j<3;j++) se[j].clear();
	for(ll i=1;i<=n;i++) mx[i][0]=mx[i][1]=-1,mxid[i]=0;
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<3;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]>mx[i][0]){
				mx[i][1]=mx[i][0];
				mx[i][0]=a[i][j];
				mxid[i]=j;
			}else mx[i][1]=max(mx[i][1],a[i][j]);
		}
}
void solve(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=mx[i][0];
		se[mxid[i]].insert(mx[i][0]-mx[i][1]);
	}
	ll j;
	for(j=0;j<3;j++)
		if(se[j].size()>n/2) break;
	if(j==3) printf("%lld\n",ans);
	else{
		while(se[j].size()>n/2){
			ll now=*se[j].begin(); se[j].erase(se[j].begin());
			ans-=now;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T; scanf("%lld",&T);
	for(ll t=1;t<=T;t++){
		input();
		solve();
	}
	return 0;
}

