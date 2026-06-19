#include<bits/stdc++.h>
using namespace std;
long long c[1009];
long long yh[1009][1009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		yh[i][i]=c[i];
	}
	for(long long i=1;i<=n;i++){
		long long tmp=c[i];
		for(long long j=i+1;j<=n;j++){
			tmp^=c[j];
			yh[i][j]=tmp;
		}
	}
	long long dp[1009];
	for(long long i=0;i<=n;i++){
		dp[i]=0;
	}
	if(c[1]==k) dp[1]=1;
	else dp[1]=0;
	for(long long i=2;i<=n;i++){
		bool ok=0;
		for(long long j=1;j<=i;j++){
			if(yh[j][i]==k){
				ok=1;
				dp[i]=max(dp[i-1],dp[j-1]+1);
			}
		}
		if(!ok) dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}
