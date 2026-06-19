#include<bits/stdc++.h>
//inclue<bits/extc++.h>
using namespace std;
#define mod 998244353
long long n,m,a[5009],dp[20009],ans;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=10002;j++) ans+=dp[j],ans%=mod;
		for(int j=10002;j>=0;j--){
			if(j+a[i]>=10002) dp[10002]+=dp[j],dp[10002]%=mod;
			else dp[j+a[i]]+=dp[j],dp[j+a[i]]%=mod; 
		}
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;//cin>>T;
	while(T--) solve();
}
//subscribe tasho11y(uid=1385732) in bilibili(in luogu)!!! 
//S rp++
//AK at 10:36 

