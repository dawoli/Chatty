#include<bits/stdc++.h>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6}; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int dp[n+10];
		dp[0]=dp[1]=-1;
		dp[2]=1;
		dp[3]=7;
		dp[4]=4;
		dp[5]=2;
		dp[6]=6;
		dp[7]=8;
		dp[8]=10;
		for(int i=9;i<=n;i++){
			dp[i]=min(min(min(dp[i-2]*10+1,dp[i-3]*10+7),min(dp[i-4]*10+4,dp[i-5]*10+2)),min(dp[i-6]*10,dp[i-7]*10+8));
		}
		if(dp[n]) cout<<dp[n];
		else cout<<-1;
		cout<<"\n";
	}
}
