#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5000+5;
const int mod = 998244353;
int n,m,a[N],dp[2*N],ans;
int qpow(int a,int n,int p){
	int ans=1;
	while(n){
		if(n&1) ans=ans*a%p;
		n>>=1,a=a*a%p;
	}
	return ans%p;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],m=max(m,2*a[i]);
	sort(a+1,a+1+n);
	for(int i=0;i<=m;++i) dp[i]=1;
	for(int i=1;i<=n;++i){
		ans=(ans+(qpow(2,i-1,mod)-dp[a[i]]+mod)%mod)%mod;
		for(int j=m;j>=a[i];--j){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
