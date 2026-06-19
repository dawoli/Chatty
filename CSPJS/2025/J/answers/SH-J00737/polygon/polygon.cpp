#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[500001];
	long long sum=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	else if(n==3){
		if(sum>a[n]*2){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	else{
		int dp[1000101]={0};
		for(int i=1;i<=n;++i){
			dp[i]=max(dp[i],dp[i-a[i]]+a[i]);
		}
		cout<<dp[n]<<endl;
		return 0;
	}
	return 0;
}
