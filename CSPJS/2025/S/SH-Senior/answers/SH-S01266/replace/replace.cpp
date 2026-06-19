#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using ll=long long;
struct Rep{
	std::string s1,s2;
};
int main(){ 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	std::cin>>n>>q;
	std::vector<Rep>rps(n);
	for(auto&i:rps){
		std::cin>>i.s1>>i.s2;
	}
	while(q--){
		std::string t1,t2;
		std::cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			std::cout<<0<<std::endl;
			continue;
		}
		ll num=0;
		for(auto&i:rps){
			size_t pos=t1.find(i.s1);
			if(pos!=std::string::npos){
				std::string rpd=t1.substr(0,pos)+i.s2+t1.substr(pos+i.s1.size());
				if(rpd==t2){
					num++;
				}
			}
		}
		std::cout<<num<<std::endl;
	}
	return 0;
}
