#include <bits/stdc++.h>
using namespace std;
int n,T,a=0,b=0,c=0,dp[100005][4],s[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					dp[i][j]=max(dp[i][j],dp[i-1][k]);
				}
				dp[i][j]+=s[i][j];
			}
		}
		cout<<max({dp[n][1],dp[n][2],dp[n][3]});
	}
	return 0;
}
