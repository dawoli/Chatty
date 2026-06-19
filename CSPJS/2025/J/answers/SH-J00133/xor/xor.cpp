#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],ans,dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(ll i=1; i<=n; i++) cin >> a[i];
	for(ll i=n; i>=1; i--){
		ll h=0,f=1e9;
		for(ll j=i; j<=n; j++){
			if(j==i) ans=a[j];
			else ans=ans^a[j];
			if(ans==k){
				f=j+1;
				break;
			}
		}
		if(f!=1e9) h=dp[f]+1;
		dp[i]=max(dp[i+1],h);
	}
	cout << dp[1];
	return 0;
}
