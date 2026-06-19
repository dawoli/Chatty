#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
int n,maxa,a[5010];//dp[i]表示和为i的方案数 
long long ans,dp[5002];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	maxa=0; 
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=maxa;j++){
				ans=(ans+dp[j])%inf;
			}
		}
		for(int j=a[i]+maxa;j>=a[i];j--){
			if(dp[j-a[i]]){
				if(j<=5000)dp[j]=(dp[j]+dp[j-a[i]])%inf;
				else dp[5001]=(dp[5001]+dp[j-a[i]])%inf;
			}
		}
		maxa=min(5001,maxa+a[i]);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
