#include <bits/stdc++.h>

std::string s ; 
std::vector<char> v ;

int main()
{
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	std::cin >> s ;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] >= '0' and s[i] <= '9') v.push_back(s[i]) ;
	}
	sort(v.begin() , v.end()) ;
	while(!v.empty())
	{
		std::cout << v.back() ;
		v.pop_back() ; 
	} 
	return 0 ;
}
