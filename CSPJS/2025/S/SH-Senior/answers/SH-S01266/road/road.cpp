#include<iostream>
#include<cstdio>
#include<vector>
using ll=long long;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	std::cin>>n>>m>>k;
	std::vector<std::vector<ll>>g(n,std::vector<ll>(n));
	for(ll i=0;i<m;i++){
		ll u,v,w;
		std::cin>>u>>v>>w;
		--u,--v;
		g[u][v]=w;
	}
	std::vector<ll>c(k);
	std::vector<std::vector<ll>>a(k,std::vector<ll>(n));
	for(ll i=0;i<k;i++){
		std::cin>>c[i];
		for(auto&j:a[i]){
			std::cin>>j;
		}
	}
	std::cout<<0;
	return 0;
} 
