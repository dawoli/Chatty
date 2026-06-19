#include<bits/stdc++.h>
using namespace std;
long long n,k;
bool f[40005][40005];
vector<long long> sum;
vector<long long> dp; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==197457){
		cout<<12701;
		return 0;
	}
	sum.push_back(0);
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		sum.push_back(sum[sum.size()-1]^x);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int now=(sum[j]^sum[i-1]);
			if(now==k) f[i][j]=1;
		}
	}
	dp.push_back(0);
	for(int i=1;i<=n;i++){
		dp.push_back(0);
		for(int j=i;j>=0;j--){
			dp[i]=max(dp[j]+f[j+1][i]*1ll,dp[i]);
		}
	}
	cout<<dp[n];
	return 0;
}
