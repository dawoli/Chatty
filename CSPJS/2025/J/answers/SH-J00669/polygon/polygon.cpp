#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
long long ans;
long long cnt=1;
long long a[5009];
long long dp[5009][5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cnt=(cnt*2)%mod;
		dp[i][0]=cnt;
		//cout<<dp[i][0]<<endl;
	}
	int m=*max_element(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		if(a[1]>i) dp[1][i]=1;
		//cout<<a[1]<<" "<<i<<endl;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==a[i]) dp[i][j]=max((long long)0,dp[i-1][j]+dp[i-1][0]-1)%mod;
			else dp[i][j]=(dp[i-1][j]+dp[i-1][max((long long)0,j-a[i])])%mod;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	for(int i=2;i<n;i++){
		ans=(ans+dp[i][a[i+1]])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
