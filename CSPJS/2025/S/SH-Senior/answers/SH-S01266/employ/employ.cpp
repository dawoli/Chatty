#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using ll=long long;
const ll MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	std::string s;
	std::cin>>n>>m>>s;
	std::vector<ll>d(n),x(n);
	for(auto&i:x){
		std::cin>>i;
	}
	bool flag=true;
	for(auto&c:s){
		if(c!='1'){
			flag=false;
			break;
		}
	}
	if(flag){
		ll ans=1;
		for(ll i=1;i<=x.size();i++){
			ans=ans*i%MOD;
		}
		std::cout<<ans; 
		return 0;
	}
	for(ll i=0;i<n;i++){
		d[i]=!(s[i]^48);
	}
	for(ll i=1;i<n;i++){
		d[i]+=d[i-1];
	}
	std::sort(x.begin(),x.end());
	ll ans=0;
	do{
		ll now=n;
		for(ll i=0;i<n;i++){
			if(x[i]<=d[i]){
				now--;
			}
		}
		if(now>=m){
			ans=(ans+1)%MOD;
		}
	}while(std::next_permutation(x.begin(),x.end()));
	std::cout<<ans;
	return 0;
}
