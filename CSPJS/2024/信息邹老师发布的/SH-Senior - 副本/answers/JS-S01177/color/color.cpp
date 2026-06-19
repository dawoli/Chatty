#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n;
int a[N];
long long dp[N][N];
void MAIN(){
	
	memset(dp,0,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=dp[i-1][j]+(a[i]==a[i-1])*a[i];
		}
		for(int j=1;j<i-1;j++){
			dp[i][i-1]=max(dp[i][i-1],dp[i-1][j]+(a[i]==a[j])*a[i]);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return;
} 

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--) MAIN();
	return 0;	
}
