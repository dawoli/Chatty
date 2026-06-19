#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010],dp[500010]={0};
	cin>>n>>k>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	if(a[0]==k)
		dp[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(j==0){
				if(a[i]==k){
					dp[i]=max(dp[i],1);
				}
				continue;
			}	
			dp[i]=max(dp[i],dp[j]);
			if((a[j]^a[i])==k){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n-1];
	return 0;
}

