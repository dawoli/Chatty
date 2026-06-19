#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000010],dd;
int dp[2][110][110],dp2[200010][10][10];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		dd=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dd=max(dd,a[i]);
		}
		if(dd>110){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<=dd;i++){
			for(int j=0;j<=dd;j++){
				dp[0][i][j]=dp[1][i][j]=-1e8;
			}
		}
		dp[0][0][0]=dp[1][0][0]=0;
		int p=0;
		for(int k=1;k<=n;k++){
			for(int i=0;i<=dd;i++){
				for(int j=0;j<=dd;j++){
					dp[p][i][j]=-1e8;
				}
			}
			for(int i=0;i<=dd;i++){
				for(int j=0;j<=dd;j++){
					if(a[k]==i){
						dp[p][a[k]][j]=max(dp[p][a[k]][j],dp[p^1][i][j]+i);
					}
					if(a[k]==j){
						dp[p][i][a[k]]=max(dp[p][i][a[k]],dp[p^1][i][j]+j);
					}
					dp[p][a[k]][j]=max(dp[p][a[k]][j],dp[p^1][i][j]);
					dp[p][i][a[k]]=max(dp[p][i][a[k]],dp[p^1][i][j]);
				}
			}
			p^=1;
		}
		int ans=0;
		for(int i=0;i<=dd;i++){
			for(int j=0;j<=dd;j++){
				ans=max(ans,dp[p^1][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
