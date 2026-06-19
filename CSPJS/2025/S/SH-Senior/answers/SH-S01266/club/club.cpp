#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using ll=long long;
ll dfs(ll x,ll n,ll sum,std::vector<std::vector<ll>>&a,std::vector<ll>&num){
	if(x==n){
		return sum;
	}
	ll ans=0;
	for(ll i=0;i<3;i++){
		if(num[i]<n/2){
			num[i]++;
			ans=std::max(ans,dfs(x+1,n,sum+a[x][i],a,num));
			num[i]--;
		}
	}
	return ans;
}
void solveBF(ll&n,std::vector<std::vector<ll>>&a){
	std::vector<ll>num(n);
	std::cout<<dfs(0,n,0,a,num)<<std::endl;
}
void solve2(ll&n,std::vector<std::vector<ll>>&a){
	std::sort(a.begin(),a.end(),[](std::vector<ll>&a1,std::vector<ll>&a2){return std::max(a1[0],a1[1])>std::max(a2[0],a2[1]);});
	ll ans=0;
	std::vector<ll> num(n);
	for(ll i=0;i<n;i++){
		ll maxi;
		if(a[i][0]>a[i][1]){
			maxi=0;
		}
		else{
			maxi=1;
		}
		if(num[maxi]<n/2){
			num[maxi]++;
			ans+=a[i][maxi];
		}
		else{
			num[!maxi]++;
			ans+=a[i][!maxi];
		}
	}
	std::cout<<ans<<std::endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	std::cin>>t;
	while(t--){
		ll n;
		std::cin>>n;
		std::vector<std::vector<ll>>a(n,std::vector<ll>(3));
		for(auto&i:a){
			for(auto&j:i){
				std::cin>>j;
			}
		}
		if(n<=10){
			solveBF(n,a);
		}
		else{
			solve2(n,a);
		}
	}
	return 0;
}
