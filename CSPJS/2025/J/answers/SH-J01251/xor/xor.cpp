#include<cstdio>
#include<iostream>
#include<vector>
typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	std::cin>>n>>k;
	std::vector<ll>a(n);
	for(auto&i:a){
		std::cin>>i;
	}
	std::vector<bool>used(n);
	ll num=0;
	for(ll len=1;len<=n;len++){
		ll l=0,r=len-1,sum=0;
		for(ll i=l;i<=r;i++){
			sum^=a[i];
		}
		for(;r<n;l++,r++){
			if(sum==k){
				bool flag=true;
				for(ll i=l;i<=r;i++){
					if(used[i]){
						flag=false;
						break;
					}
				}
				if(flag){
					num++;
					for(ll i=l;i<=r;i++){
						used[i]=true;
					}
				}
			}
			if(r+1<n){
				sum^=a[l];
				sum^=a[r+1];
			}
		}
	}
	std::cout<<num;
	return 0;
}
