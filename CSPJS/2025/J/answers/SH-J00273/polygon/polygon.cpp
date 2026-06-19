#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int b[5005];
int dp[5005];
int ans;
int cal(int x){
	int res=0;
	for(int i=1;i<=x;i++){
		int sum1=1,sum2=1;
		for(int k=0;k<i;k++){
			sum1*=x-k;
			sum1%=mod;
			sum2*=i-k;
			sum2%=mod;
		}
		res+=sum1/sum2;
		res%=mod;
	}
	return res;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int j=1;j<i;j++){
			for(int k=a[i];k>=a[j];k--){
				dp[k]+=dp[k-a[j]]%mod;
				dp[k]%=mod;
			}
		}
		int sum=0;
		for(int j=1;j<=a[i];j++){
			sum+=dp[j];
			sum%=mod; 
		}
		ans+=(cal(i-1)%mod-sum%mod)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
