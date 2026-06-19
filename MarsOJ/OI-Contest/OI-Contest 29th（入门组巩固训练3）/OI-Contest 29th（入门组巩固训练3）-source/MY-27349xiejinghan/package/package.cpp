#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int dp[1000][1000],cost[1000][1000],v[10000],w[10000],mm[10000];
int main(){
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>mm[i];
	for (int i=1;i<=n;i++) cin>>v[i]>>w[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<w[i]) dp[i][j]=dp[i-1][j],cost[i][j]+=cost[i-1][j]+mm[v[i]];
			else if(dp[i-1][j]<=dp[i][j-w[i]]+v[i]){
				dp[i][j]=dp[i-1][j],cost[i][j]+=cost[i-1][j]+mm[v[i]];
			}else{
				dp[i][j]=dp[i][j-w[i]]+v[i],cost[i][j]+=cost[i][j-w[i]]+mm[v[i]]+mm[v[i]];
			}
		}
	}
	cout<<cost[n][m];
	return 0;
}
