#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll n,ls[505],c,ans,dp[505][505],cnt,chs;
bool w=1;
void dps(ll s,ll p,ll d){
	if(p>n){
		if(s>ls[chs] && d>=2){
			c=(c+1)%MOD;
//			cout<<t;
//			cout<<chs<<endl;
		}
		return ;
	}
//	cout<<" "<<t<<endl;
	dps(s,p+1,d);
	if(p+1<chs) dps(s+ls[p+1],p+1,d+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>ls[i];
		cnt+=ls[i];
		if(ls[i]!=1){
			w=0;
		}
	}
	sort(ls+1,ls+n+1);
	if(w==1){
		for(ll i=4;i<=n;i++){
			ans=1;
			for(ll j=i+1;j<=n;j++){
				ans=(ans*j)%MOD;
			}
			c=(c+ans)%MOD;
		}
		cout<<c<<endl;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		chs=i;
		c=0;
		dps(0,0,0);
		ans=(ans+c)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
