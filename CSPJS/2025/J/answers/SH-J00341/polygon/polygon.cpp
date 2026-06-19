#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define N 5100
int n,a[N],dp[N],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans*=2;
		ans%=mod;
	}
	ans+=mod-1;
	ans%=mod;
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			ans+=mod-dp[j];
			ans-=(ans>=mod)*mod;
		}
		for(int j=5000;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]-=(dp[j]>=mod)*mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
