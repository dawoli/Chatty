#include<algorithm>
#include<cstdio>
#include<iostream>
#include<functional>
#include<vector>
typedef long long ll;
struct Node{
	ll num,id;
	bool operator>(Node other)const{
		return this->num>other.num;
	}
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	std::cin>>n>>m;
	std::vector<Node>a(n*m+1);
	for(ll i=1;i<=n*m;i++){
		std::cin>>a[i].num;
		a[i].id=i;
	}
	std::sort(a.begin()+1,a.end(),std::greater<Node>());
	for(ll i=1;i<=n*m;i++){
		if(a[i].id==1){
			ll c=(i+n-1)/n,r=i-(c-1)*n;
			if(!(c&1)){
				r=m-r+1;
			}
			std::cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}
