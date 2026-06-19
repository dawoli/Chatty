#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],cnt,dp[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i = 1; i<=n; i++) cin>>a[i];
	dp[0]=0;
	if(a[1]==k) dp[1]=dp[0]+1;
	else dp[1]=dp[0];
	for(int i = 2; i<=n; i++) {
		if(a[i]==k) dp[i]=dp[i-1]+1;
		else if(a[i-1]^a[i]==k) dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	}
	cout<<dp[n]-1;
	return 0;
}

