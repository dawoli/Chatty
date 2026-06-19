#include<bits/stdc++.h>
using namespace std;

int n,k,a[500009],dp[500009];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int t=0;
		for(int j=i;j>=1;j--){
			t^=a[j];
			if(t==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}
/*
20行的break真的对吗？？
*/ 
