#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100005],ans;
int c[100005];
int dp[110][110][2];
void dfs(int now){
	int x=0,y=0,val=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			if(a[i]==x){
				val=a[i];	
			}
			x=a[i];
		}
		else{
			if(a[i]==y){
				val=a[i];
			}
			y=a[i];
		}
		ans=max(ans,val);
		return;
	}
	c[now]=0;
	dfs(now+1);
	c[now]=1;
	dfs(now+1);
} 
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=15){
			ans=0;
			dfs(1);
			cout<<ans; 
		}
		else{
			ans=0;
			for(int i=2;i<=n;i++){
				for(int j=0;j<=i-2;j++){
					for(int k=0;k<=j-1;k++){
						dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
					}
				}
				for(int j=0;j<=i-2;j++){
					dp[i][j][1]=dp[i-1][j][0]-(a[i]-a[j]);
				}
				for(int k=0;k<=i-3;k++){
					dp[i][k-2]][1]=max(dp[i][k-2][1],dp[i-1][k][1]);
				}
			}
			for(int j=0;j<=n-2;j++){
				ans=max(ans,max(dp[n][j][0],dp[n][j][1]));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
