#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

// Point 1,2
long long n,a[200005],ans; 
bool col[20];

// Point 5~10
long long dp[2001][2][2001];

void dfs(long long u) {
	if(u==n+1) {
		long long latest[2]={0,0},sum=0;
		for(long long i=1;i<=n;i++) {
			if(a[i]==latest[col[i]]) sum+=a[i];
			latest[col[i]]=a[i];
		}
		ans=max(ans,sum);
		return;
	}
	col[u]=0;
	dfs(u+1);
	col[u]=1;
	dfs(u+1);
	return;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long t;
	cin>>t;
	while(t--) {
		cin>>n;
		long long maxa=0;
		for(long long i=1;i<=n;i++) cin>>a[i],maxa=max(maxa,a[i]);
		if(n<=15) {
			ans=0;
			dfs(1);
			cout<<ans<<endl;
		}
		else if(n<=2000) {
			memset(dp,0,sizeof dp);
			for(long long i=2;i<=n;i++) {
				//red
				for(long long j=0;j<i-1;j++) {
					dp[i][0][j]=max(dp[i][0][j],dp[i-1][0][j]+((a[i]==a[i-1])?a[i]:0));
					dp[i][0][i-1]=max(dp[i][0][i-1],dp[i-1][1][j]+((a[i]==a[j])?a[i]:0));
					dp[i][1][j]=max(dp[i][1][j],dp[i-1][1][j]+((a[i]==a[i-1])?a[i]:0));
					dp[i][1][i-1]=max(dp[i][1][i-1],dp[i-1][0][j]+((a[i]==a[j])?a[i]:0));
				}
			}
			ans=0;
			for(long long i=0;i<n;i++) ans=max(ans,max(dp[n][0][i],dp[n][1][i]));
			cout<<ans<<endl;
		}
	}
	return 0;
}
