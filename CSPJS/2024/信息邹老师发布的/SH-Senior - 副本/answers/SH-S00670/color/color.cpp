#include<bits/stdc++.h>
using namespace std;
int A[200010];
long long dp[200010];
long long btn(int x){
	long long sum=0,mx=0;
	int i=0;
	for(i=x-1;i>=0;i--){
		if(A[i]==A[x]){
			sum+=A[i];
			break;
		}
		if(A[i]==A[i+1]){
			sum+=A[i];
		}
	}
	if(i<x-1){
		return max(dp[x-1],dp[i+1]+sum);
	}
	else{
		return dp[x-1]+A[x];
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T,n;
	int i;
	cin>>T;
	while(T>0){
		cin>>n;
		memset(A,sizeof(A),0);
		memset(dp,sizeof(dp),0);
		for(i=0;i<n;i++){
			cin>>A[i];
			if(i==0){
				dp[i]=0;
			}
			else{
				dp[i]=btn(i);
			}
		}
		cout<<dp[n-1]<<endl;
		T--;
	}
	return 0;
}
