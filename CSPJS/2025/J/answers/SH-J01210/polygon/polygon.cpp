#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[100010],m;
long long dp[100010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		m = max(m,a[i]);
	}
	m = m*2;
	ans = dp[0] = 1;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = m*2;j >= a[i];j--){
			if(j<=2*a[i]){
				ans += dp[j-a[i]];
				ans %= mod;
			}
			dp[j] += dp[j-a[i]];
			dp[j] %= mod;
		}
	}
	long long k = 1;
	for(int i = 1;i <= n;i++) k = k*2%mod;
	cout<<(k-ans+mod)%mod;
	return 0;
}
