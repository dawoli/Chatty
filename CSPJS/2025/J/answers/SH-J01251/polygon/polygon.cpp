#include<algorithm>
#include<cstdio>
#include<iostream>
#include<numeric>
#include<vector>
typedef long long ll;
const ll MOD=998244353LL;
std::vector<ll>now,a;
ll n,ans=0;
void dfs(ll x){
	if(x==n){
		if(!now.size()){
			return;
		}
		ll maxn=*std::max_element(now.begin(),now.end()),sum=std::accumulate(now.begin(),now.end(),0);
		if(sum>2*maxn){
			ans=(ans+1)%MOD;
		}
		return;
	}
	dfs(x+1);
	now.push_back(a[x]);
	dfs(x+1);
	now.pop_back();
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	a.resize(n);
	for(auto&i:a){
		std::cin>>i;
	}
	dfs(0);
	std::cout<<ans;
	return 0;
}
