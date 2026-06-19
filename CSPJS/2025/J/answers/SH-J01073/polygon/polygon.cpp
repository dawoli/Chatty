#include<bits/stdc++.h>
using namespace std;
int C(int a,int b){
	int sum=1,sum2=1;
	for(int i=b,times=1;times<=a;times++,i--){
		sum*=i;
	}
	for(int i=a;i>=1;i--){
		sum2*=i;
	}
	return sum/sum2;
}
int main(){
	int n,a[505];
	int dp[505];
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	cin>>n;
	dp[1]=0;
	dp[2]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=2;j<=i-1;j++){
			dp[i]+=C(j,i-1);
		}
		
	}
	cout<<dp[n];
	return 0;
}
