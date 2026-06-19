#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,ans;
ll a[5009];
ll dp[5][7000000];
ll c(ll k){
	if(k%2==0)return 0;
	else return 1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	maxx=a[n];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=maxx*n;j++){
			dp[c(i)][j]=0;
			
			dp[c(i)][j]+=dp[c(i-1)][j];
			
			dp[c(i)][j]%=mod;
			
			if(j-a[i-1]>=1)dp[c(i)][j]+=dp[c(i-1)][j-a[i-1]];
			
			dp[c(i)][j]%=mod;
			
			if(j==a[i-1])dp[c(i)][a[i-1]]++;
			
			dp[c(i)][j]%=mod;
			
			if(j>a[i])ans+=dp[c(i)][j];
			
			ans%=mod;
		
		}
	}
	cout<<ans%mod;
	return 0;
}
//1 8 12 14 14 15 26 26 28 35 37 38 42 43 75 83 84 90 90 98
