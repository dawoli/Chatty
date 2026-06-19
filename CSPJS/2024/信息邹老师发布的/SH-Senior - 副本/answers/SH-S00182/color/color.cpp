#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring> 
#include<algorithm>
#define int long long
int t,n,a[101],dp[101][101][101];//第i个位置，上一个蓝色，最大方案 
void solve(){
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k]=-1e14;
			}
		}
	}
	dp[1][0][1]=0;
	dp[1][1][0]=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<i;k++){
				if((j==k) or ( (j!=i-1) and (k!=i-1))) continue;
				dp[i][i][k]=std::max(dp[i][i][k],dp[i-1][j][k]);
				dp[i][j][i]=std::max(dp[i][j][i],dp[i-1][j][k]);
				if(a[i]==a[j]){
					dp[i][i][k]=std::max(dp[i][i][k],dp[i-1][j][k]+a[i]);
				}
				if(a[i]==a[k]){
					dp[i][j][i]=std::max(dp[i][j][i],dp[i-1][j][k]+a[i]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==j or ((i!=n) and (j!=n))) continue;
			ans=std::max(ans,dp[n][i][j]);
		}
	}
	std::cout<<ans<<"\n";
//	for(int i=1;i<=n;i++){
//		std::cout<<i<<" "<<dp[i][i]<<"\n";
//	}
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	std::cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

1
100
17 18 18 19 17 19 20 20 18 19 18 19 18 19 19 19 18 17 19 17 40 40 40 37 40 39 39 39 38 39 38 40 37 40 38 40 38 39 39 40 59 60 58 60 59 58 59 58 60 57 58 60 57 60 57 60 58 60 57 60 80 80 79 80 78 77 80 79 79 80 79 79 79 77 80 77 77 80 80 78 100 100 98 97 97 99 98 99 100 99 100 98 98 99 98 98 100 100 97 98

*/


