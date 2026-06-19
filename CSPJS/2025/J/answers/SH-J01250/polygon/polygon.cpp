#include <bits/stdc++.h>
using namespace std;
//50005
unsigned long long ans=0;
unsigned long long n,a[5005],f[5005],dp[505][1005],fdp[505][1005];
int  mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for( unsigned long long i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
	}
	
	sort(a+1,a+n+1);
	for( unsigned long long i=1;i<=n;i++){
		for( unsigned long long j=0;j<=f[i];j++){
			dp[i][j]=dp[i-1][j]%mod;
			if(j==a[i]){
				dp[i][j]++;
			}
			if(j>=a[i]&&dp[i-1][j-a[i]]){
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
			}
		}
	}
	for( unsigned long long i=1;i<=n;i++){
		for( unsigned long long j=0;j<=f[i];j++){
			if(j==0){
				fdp[i][j]=(mod+dp[i][j])%mod;
				continue;
			}
			fdp[i][j]=(mod*2+fdp[i][j-1]+dp[i][j])%mod;

		}
	}
	for( unsigned long long i=1;i<=n;i++){
		for( unsigned long long j=0;j<=f[i];j++){
			fdp[i][j]=fdp[i][j]%mod;
		}
	//	cout<<endl; 
	}
	 
	for( unsigned long long i=1;i<=n;i++){
		if(f[i-1]>=a[i]&&fdp[i-1][f[i-1]]-fdp[i-1][a[i]]>=0){
			
//		cout<<"i="<<i<<endl;
//		cout<<"f[i-1]="<<f[i-1]<<endl;
//		cout<<"fdp[i-1]["<<f[i-1]<<"]="<<fdp[i-1][f[i-1]]<<endl;
//		cout<<"fdp[i-1]["<<a[i]<<"]="<<fdp[i-1][a[i]]<<endl;
		//u=a[i];
		ans=(mod*2+ans+fdp[i-1][f[i-1]]-fdp[i-1][a[i]])%mod;
		
//		cout<<"ans+="<<(mod*2+fdp[i-1][f[i-1]]-fdp[i-1][a[i]])%mod<<endl;
		ans%=mod;
//		cout<<"ans="<<ans%mod<<endl;
//		cout<<endl;
		}
	}
	cout<<ans%mod<<endl;
	return 0;
} 
