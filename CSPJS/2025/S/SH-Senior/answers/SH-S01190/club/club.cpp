#include<bits/stdc++.h>
using namespace std;
int t;
int num[3][100005];
int dp[202][202][202];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		int n,ans=0;
		bool typeb=true,typea=true; 
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>num[0][i]>>num[1][i]>>num[2][i];
			if(num[2][i]!=0) typeb=typea=false;
			if(num[1][i]!=0) typeb=false;
		}
		if(typea){
			sort(num[0]+1,num[0]+n+1);
			for(int i=n;i>=n/2;i--)
				ans+=num[0][i];
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[1][0][0]=num[0][1];
		dp[0][1][0]=num[1][1];
		dp[0][0][1]=num[2][1];
		for(int k=2;k<=n;k++){
			for(int i=0;i<=k;i++){
				for(int j=0;j<=k;j++){
					if(k-i-j>n/2||i>n/2||j>n/2) continue;
					if( (dp[i-1][j][k-i-j]+num[0][k]>dp[i][j][k-i-j]) && i>0){
						dp[i][j][k-i-j]=dp[i-1][j][k-i-j]+num[0][k];
					}
					if( (dp[i][j-1][k-i-j]+num[1][k]>dp[i][j][k-i-j]) && j>0){
						dp[i][j][k-i-j]=dp[i][j-1][k-i-j]+num[1][k];
					}
					if( (dp[i][j][k-i-j-1]+num[2][k]>dp[i][j][k-i-j]) && k-i-j>0){
						dp[i][j][k-i-j]=dp[i][j][k-i-j-1]+num[2][k];
					}
				}
			}
		}
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++){
				ans=max(ans,dp[i][j][n-i-j]);	
			}
		cout<<ans<<endl;
	}
	return 0;
}
