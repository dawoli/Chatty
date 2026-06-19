#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
// so easy!
//O(n^2)
int dp[6000][6000];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[n];
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a,a+n);
	int ans=0,ans2=0;
	for(int i=0;i<n-1;i++){
		if(i>0){
			for(int j=a[i]+1;j<maxn+2;j++){
				ans2+=dp[i-1][j];
			}
			for(int j=0;j<=maxn+1;j++){
				dp[i][j]+=dp[i-1][j];
				dp[i][j]%=mod;
			}
			for(int j=0;j<=maxn+1;j++){
				if(j+a[i]>maxn){
					dp[i][maxn+1]+=dp[i-1][j];
					dp[i][maxn+1]%=mod; 
				}else{
				//	if(j+a[i]>a[i+1]){
				//		ans+=dp[i-1][j];
				//		ans%=mod;
				//	}
					dp[i][j+a[i]]+=dp[i-1][j];
					dp[i][j+a[i]]%=mod;
				}
			}
		//	ans+=dp[i][maxn+1];
		//	ans%=mod;
		}
		
		dp[i][a[i]]++;
		/*
		for(int j=0;j<maxn+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
		*/
	}
	ans2+=dp[n-2][maxn+1];
	cout<<ans2%mod<<endl;
	return 0;
} 
