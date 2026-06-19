#include<bits/stdc++.h>
using namespace std;
int n,a[1009],dp[5003*5003],sum,ans;
const int mod=998244353;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	dp[a[1]]=1;
	for(int i=2; i<=n; i++) {
		//cout<<i<<"\n";
		if(i>=3) {
//			for(int j=0;j<=sum;j++) {
//				cout<<dp[j]<<" "<<a[i]<<" "<<j<<"\n";
//			}
			for(int j=a[i]+1; j<=sum; j++) {
				ans=(ans+dp[j])%mod;
			}
			//cout<<ans<<"\n";
		}
		for(int j=sum; j>=a[i]; j--) {
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	//for(int i=0;i<=sum;i++) cout<<dp[i]<<" ";
	cout<<ans;
	return 0;
}
