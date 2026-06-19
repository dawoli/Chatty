#include<algorithm>
#include<cctype>
#include<cstdio>
#include<functional>
#include<iostream>
#include<string>
#include<vector>
typedef long long ll;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
    std::string s;
    std::cin>>s;
    std::vector<ll>nums;
    for(auto&c:s){
        if(std::isdigit(c)){
            nums.push_back(c^48);
		}
    }
    std::sort(nums.begin(),nums.end(),std::greater<ll>());
    for(auto&i:nums){
        std::cout<<i;
    }
    return 0;
}
