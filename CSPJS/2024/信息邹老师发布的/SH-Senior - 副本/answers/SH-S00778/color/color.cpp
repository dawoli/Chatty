#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=2e3+10,inf=0x3f3f3f3f;
int n,a[N],dp[N][N][2],f[N][2];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		memset(dp,0,sizeof dp);
		dp[1][1][0]=dp[1][1][1]=0;
		int ans=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i-1;j++){
				dp[i][1][0]=max(dp[i][1][0],dp[i-1][i-j-1][1]+((a[i]==a[j])?a[i]:0));
				dp[i][1][1]=max(dp[i][1][1],dp[i-1][i-j-1][0]+((a[i]==a[j])?a[i]:0));
			}if(i==n)ans=max(ans,max(dp[i][1][0],dp[i][1][1]));
			//cout<<dp[i][1][0]<<" ";
			for(int j=2;j<=i;j++){
				dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][0]+((a[i-1]==a[i])?a[i]:0));
				dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][1]+((a[i-1]==a[i])?a[i]:0));
				if(i==n)ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
				//cout<<dp[i][j][0]<<" ";
			}
			//cout<<endl;
			//cout<<dp[i][0]<<dp[i][1]<<endl;
			
		}
		cout<<ans<<endl;
	}
	return 0;
} 
