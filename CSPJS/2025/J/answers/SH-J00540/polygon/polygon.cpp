#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll s[5010][5010];
ll n,a[5010];
ll qp(ll x,ll y){
	if(y==1)	return x;
	else if(y%2==0){
		ll t=qp(x,y/2);
		t*=t; t%=MOD;
		return t;
	}
	else{
		ll t=qp(x,y/2);
		t*=t; t%=MOD; t*=x; t%=MOD;
		return t;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i)	cin>>a[i];
	sort(a+1,a+n+1);
	s[0][0]=1;
	for(ll i=1;i<=n;++i)
		for(ll j=0;j<=5000;++j){
			ll x=0;
			x+=s[i-1][j]; x%=MOD;
			if(j>=a[i])	x+=s[i-1][j-a[i]];
			x%=MOD;
			s[i][j]=x;
		}
	ll sm=0;
	for(ll i=3;i<=n;++i){
		ll cnt=qp(2,i-1),ans=0;
		for(ll j=0;j<=a[i];++j){
			ans+=s[i-1][j];
			ans%=MOD;
		}
		sm+=(cnt-ans);
		sm%=MOD;
	}
	cout<<sm<<endl;
}
