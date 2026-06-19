#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[MAXN][4];
		int dp[MAXN][4];
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				
			}
		}
		for(int j=1;j<=3;j++){
			for(int i=2;i<=n;i+2){
				dp[i-1][j]=max(dp[i-1][j-1],+dp[i-2][j-1]);
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
			}
			
		}
		cout<<dp[n][3]<<endl;
	}
	return 0;
}
