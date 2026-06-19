#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nullptr NULL
#define MOD 998244353
ll *a=nullptr,*dp=nullptr;
map<pair<pair<ll,ll>,ll>,ll> idkh;
ll idk(ll l,ll r,ll k){
	if(idkh.count(make_pair(make_pair(l,r),k))){
		return idkh[make_pair(make_pair(l,r),k)];
	}
	ll ans=0;
	ll mid=upper_bound(a+l,a+r,k-a[l])-a;
	if(mid==l||mid==l+1){
		return 0;
	}
	ans=(ans+mid-l-1)%MOD;
	ans=(ans+idk(l+1,mid,k-a[l]))%MOD;
	ans=(ans+idk(l+1,mid,k))%MOD;
	idkh[make_pair(make_pair(l,r),k)]=ans; 
	return ans;
}
ll ksm(ll l,ll r){
	ll ans=1;
	while(r){
		if(r%2){
			ans=(ans*l)%MOD;
		}
		l=(l*l)%MOD;
		r/=2;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	a=new ll[n+1];dp=new ll[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[2]=0;
	for(int i=3;i<=n;i++){
		dp[i]=(dp[i-1]+(ksm(2,i-1)-i-idk(1,i,a[i]))%MOD)%MOD;
	}
	cout<<dp[n];
	return 0;
} 
