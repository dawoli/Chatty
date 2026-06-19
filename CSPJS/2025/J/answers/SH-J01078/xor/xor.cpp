#include <bits/stdc++.h>
using namespace std;
int n,k;
long long sum[500007];
int a[500007];
int dp[500007]; 
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		sum[i] = a[i] ^ sum[i - 1];
	}
	for(int i = 1;i<=n;i++){
		if(a[i] == k) dp[i] = 1;
	}
	for(int i = 1;i<=n;i++){
		for(int j = i - 1;j>=0;j--){
			if((sum[i]^sum[j]) == k){
				dp[i] = max(dp[i],dp[j] + 1);
			}
			else dp[i] = max(dp[i],dp[j]);
		}
	}
	for(int i = 1;i<=n;i++){
		ans = max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
} 

