#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009,A=5009,MOD=998244353;
ll a[N],dp[N];
ll ksm(ll d,ll z){
	ll ans=1;
	while(z){
		if(z&1)ans=ans*d%MOD;
		d=d*d%MOD;
		z/=2;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(i>=3){
			ll al=ksm(2,i-1);
			for(ll j=0;j<=a[i];j++)al=(al+MOD-dp[j])%MOD;
			ans=(ans+al)%MOD;
		}
		for(ll j=A-a[i]-1;j>=0;j--)dp[j+a[i]]=(dp[j+a[i]]+dp[j])%MOD;
	}
	cout<<ans;
	return 0;
}
/*
陈王昔时宴平乐，斗酒十千恣欢谑
主人何为言少钱，径须沽取对君酌
五花马，千金裘，呼儿将出换美酒，与尔同销万古愁 
*/
