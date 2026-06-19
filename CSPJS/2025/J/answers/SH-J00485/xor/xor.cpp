#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1,0);
	vector<int> px(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		px[i]=(px[i-1]^a[i]);
	}
	vector<int> dp(n+1,0);
	for(int i=1;i<=n;i++){
		int maxx=dp[i-1];
		for(int j=i-1;j>=0;j--){
			if((px[i]^px[j])==k){
				maxx=max(maxx,dp[j]+1);
			}
		}
		dp[i]=maxx;
	}
	cout<<dp[n];
	return 0;
}
