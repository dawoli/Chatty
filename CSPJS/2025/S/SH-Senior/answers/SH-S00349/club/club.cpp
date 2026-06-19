#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int a[4][100005]={};//人物满意度数组
	int dp[4][100005]={};//右=右初+左 最大值 
	for(int i=1;i<=n;i++){ 
		cin>>a[1][i]>>a[2][i]>>a[3][i];
	} 
	for(int i=1;i<=n;i++){
		if(i<=n/2){
			dp[1][i]=max(a[1][i]+dp[1][i-1],max(a[1][i]+dp[2][i-1],a[1][i]+dp[3][i-1]));
			dp[2][i]=max(a[2][i]+dp[1][i-1],max(a[2][i]+dp[2][i-1],a[2][i]+dp[3][i-1]));
			dp[3][i]=max(a[3][i]+dp[1][i-1],max(a[3][i]+dp[2][i-1],a[3][i]+dp[3][i-1]));
		}
		else if(i>=n/2){
			dp[1][i]=max(a[1][i]+dp[2][i-1],a[1][i]+dp[3][i-1]);
			dp[2][i]=max(a[2][i]+dp[1][i-1],a[2][i]+dp[3][i-1]);
			dp[3][i]=max(a[3][i]+dp[2][i-1],a[3][i]+dp[1][i-1]);
		}
	} 
	int ans=max(max(dp[1][n],dp[2][n]),dp[3][n]);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	
	int t=0;
	cin>>t;
	
	while(t){
		solve();
		t--;
	}
	
	freopen("club.out","w",stdout);
	return 0;
}
