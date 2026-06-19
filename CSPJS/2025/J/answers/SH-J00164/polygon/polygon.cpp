#include<bits/stdc++.h>
using namespace std;
int arr[5005],n;
long long su;
int dp[100000],dp1[100000];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		su+=arr[i];
	}
	
	sort(arr+1,arr+n+1);
	
	for(int i = 1;i<=su;i++) dp[i]=1;
	
	for(int i = 1;i<=n;i++){
		
		for(long long j = su;j>=3;j--){
			dp1[j]+=arr[i];
			
			if(3<=arr[i] &&((dp1[j])>(  2*(  arr[i]  )))){//¿ÉÑ¡ 
				dp[j]=dp[j]+dp[j-arr[i]];
				dp1[j]-=arr[i];
			}
			
		} 
	}
	cout<<dp[su];
	return 0;
}
