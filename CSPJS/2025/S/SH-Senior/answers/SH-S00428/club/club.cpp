#include<bits/stdc++.h>
using namespace std;
long long a[100005][5],dp[205][105][105],m;
int n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cout<<1<<endl;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		m=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=min(k-i,n/2);j++){
					if(k-i-j>0){
						dp[k][i][j]=max(dp[k-1][i][j]+a[k][3],dp[k][i][j]);
					}
					if(i>0){
						dp[k][i][j]=max(dp[k-1][i-1][j]+a[k][1],dp[k][i][j]);
					}
					if(j>0){
						dp[k][i][j]=max(dp[k-1][i][j-1]+a[k][2],dp[k][i][j]);
					}
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=min(n-i,n/2);j++){
				if(i+j>=n/2){
					m=max(m,dp[n][i][j]);
				}
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
