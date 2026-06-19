#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],dp[5010][5010],ans;
int qpow(int x){
	int ans=1,t=2;
	while (x){
		if(x&1)ans=(1ll*ans*t)%mod;
		x>>=1;
		t=(1ll*t*t)%mod;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		for(int j=0;j<=a[n];j++){
			if(j==0){
				dp[i][j]=qpow(i)-1;
			}
			else if(j-a[i]>=0)dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
			else dp[i][j]=(dp[i-1][j]+qpow(i-1))%mod;
		}
	}
	for(int i=1;i<=n-1;i++){
		ans=(ans+dp[i][a[i+1]])%mod;
	}
	cout <<ans;
	return 0;
}
