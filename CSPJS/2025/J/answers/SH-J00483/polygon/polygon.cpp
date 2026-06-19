#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5010,mod=998244353;
ll n,a[N],dp[N*N],ans;
bool flg=1;
void dfs(ll stp,ll mx,ll sum,ll m) {
	if(stp>n) {
		if(sum>mx*2 && m>=3) ans=(ans+1)%mod;
		return;
	}
	dfs(stp+1,mx,sum,m);
	dfs(stp+1,max(mx,a[stp]),sum+a[stp],m+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; ++i) {
		cin>>a[i];
		if(a[i]!=1) flg=0;
	}
	if(flg) {
		ans=1;
		for(ll i=1; i<=n; ++i) ans=ans*2%mod;
		ans=((ans-1-n-n*(n-1)/2)%mod+mod)%mod;
		cout<<ans;
	} else if(n<=20) dfs(1,0,0,0),cout<<ans;
	else {
		sort(a+1,a+n+1);
		ll s=0;
		for(ll i=1; i<=n; ++i) s+=a[i];
		dp[0]=1;
		for(ll i=1; i<=n; ++i) {
			for(ll j=a[i]+1; j<=s; ++j) ans=(ans+dp[j])%mod;
			for(ll j=s; j>=a[i]; --j) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		cout<<ans;
	}
	return 0;
}
