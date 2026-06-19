#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=3e5+5;
int dp[5][maxn],a[maxn],n,ans,T;

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T-->0){
		memset(dp,0,sizeof dp);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
			for(int j=0;j<i-1;j++){
				if(a[i]==a[j]) dp[2][i-1]=max(dp[2][i-1],dp[1][j]+a[i]);
				else dp[2][i-1]=max(dp[2][i-1],dp[1][j]);
				
				if(a[i]==a[i-1]) dp[1][j]=dp[1][j]+a[i];
			
				if(a[i]==a[j]) dp[1][i-1]=max(dp[1][i-1],dp[2][j]+a[i]);
				else dp[1][i-1]=max(dp[1][i-1],dp[2][j]);
				
				if(a[i]==a[i-1]) dp[2][j]=dp[2][j]+a[i];
			} 
		} 
		for(int i=0;i<=n;i++) ans=max(ans,max(dp[1][i],dp[2][i]));
		cout<<ans<<endl;
	}
} 
