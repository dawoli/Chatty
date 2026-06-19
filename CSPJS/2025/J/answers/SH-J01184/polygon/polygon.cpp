#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=998244353;
ll a[5005];
ll dp[26000005];//dp[i][j]表示看到第i个，和为j的情况数，取模，存在j*nn+i中，其中nn=n+1 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	dp[0]=1;
	int nn=n+1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			dp[j*nn+i]+=dp[j*nn+(i-1)];
			if(j>=a[i]) dp[j*nn+i]+=dp[(j-a[i])*nn+(i-1)];
			dp[j*nn+i]%=mod;
		}
	}
	ll ans=0;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=sum;j++){
			ans+=dp[j*nn+i-1];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
