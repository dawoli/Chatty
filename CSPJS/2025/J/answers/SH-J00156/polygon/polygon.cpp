#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5010;
int n,a[N],dp[5011];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	a[n+1]=1e9;
	for(int i=1;i<=n;i++){
		dp[5001]+=dp[5001];
		dp[5001]%=mod;
		for(int j=5000-a[i]+1;j<=5000;j++) dp[5001]+=dp[j],dp[5001]%=mod;
		for(int j=5000;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
		if(i>=2){
			for(int j=a[i+1]+1;j<=5001;j++) ans+=dp[j],ans%=mod; 
		}
	}
	cout<<ans;
	return 0;
}
