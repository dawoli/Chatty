#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=988244353;
ll solve(ll x){
	ll ans=1;
	while(x){
		ans=ans*x%MOD;
		x--;
	}
	return ans;
}
ll n,m;
string s;
ll sum[510];
ll a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(ll i=0;i<s.length();i++){
		sum[i+1]=sum[i];
		if(s[i]=='0') sum[i+1]++;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll ji=solve(n);
		sort(a+1,a+n+1,greater<ll>());
		ll ans1=1;
		for(ll i=1;i<=n;i++){
			ll wei=lower_bound(sum+1,sum+n+1,a[i])-a;
			ll lns=n-wei+1-i;
			if(lns<=0){
				cout<<ji;
				return 0;
			}
			ans1=ans1*lns%MOD;
		}
		cout<<((ji-ans1)%MOD+MOD)%MOD;
		return 0;
	}else if(m==n){
		ll ji=solve(n);
		sort(a+1,a+n+1);
		ll ans1=1;
		for(ll i=1;i<=n;i++){
			ll wei=lower_bound(sum+1,sum+n+1,a[i])-a;
			ll lns=wei-i-1;
			if(lns<=0){
				cout<<0;
				return 0;
			}
			ans1=ans1*lns%MOD;
		}
		cout<<ans1;
		return 0;
	}else{
		return 0;
	}
	return 0;
}
