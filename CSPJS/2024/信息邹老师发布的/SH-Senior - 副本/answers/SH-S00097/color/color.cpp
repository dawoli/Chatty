#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int a[101];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)   cin>>a[j];
		for(int j=1;j<=n;j++){
			for(int k=0;k<=n;k++){
				for(int l=0;l<=n;l++)    dp[j][k][l]=-1;
			}
		}
		dp[1][1][0]=0;dp[1][0][1]=0;
		for(int j=2;j<=n;j++){
			for(int k=0;k<j;k++){
				for(int l=0;l<j;l++){
					if(k!=0&&a[k]==a[j]){
						if(dp[j-1][k][l]!=-1)   dp[j][j][l]=max(dp[j-1][k][l]+a[j],dp[j][j][l]);
					}
					else{
						if(dp[j-1][k][l]!=-1)   dp[j][j][l]=max(dp[j-1][k][l],dp[j][j][l]);
					}
					if(l!=0&&a[l]==a[j]){
						if(dp[j-1][k][l]!=-1)   dp[j][k][j]=max(dp[j-1][k][l]+a[j],dp[j][k][j]);
					}
					else{
						if(dp[j-1][k][l]!=-1)   dp[j][k][j]=max(dp[j-1][k][l],dp[j][k][j]);
					}
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++)   ans=max(ans,dp[n][j][k]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
