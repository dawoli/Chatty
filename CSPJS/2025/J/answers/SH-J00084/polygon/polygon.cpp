#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],dp[5010]={1},ans,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=a[i]+1;j<=5001;j++)
			ans=(ans+dp[j])%mod;
		for(int j=5001;j>=0;j--){
			if(j+a[i]>5000)
				dp[5001]=(dp[5001]+dp[j])%mod;
			else
				dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
		}
	}
	cout<<ans;
}
