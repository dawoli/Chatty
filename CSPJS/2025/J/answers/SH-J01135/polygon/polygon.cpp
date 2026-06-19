#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll x[10009];
bool all1(){
	for(ll i=0;i<n;i++){
		if(x[i]!=1)return 0;
	}
	return 1;
}
void solve1(){
	if(x[0]+x[1]+x[2]<=2*max(x[0],max(x[1],x[2]))){
		cout<<0;
	}else cout<<1<<endl;
}
void solve2(){
	ll ans=0;
	for(ll i=3;i<=n;i++){
		ll cnt=1;
		for(ll j=0;j<i;j++){
			cnt=cnt*(n-j)/(j+1);
			cnt%=998244353;
		}
		ans+=cnt;
	}
	cout<<ans%998244353<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++)cin>>x[i];
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		solve1();
	}else if(all1){
		solve2();
	}
	return 0;
}
