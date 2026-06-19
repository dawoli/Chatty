#include <bits/stdc++.h>

int n , k , cnt0 , cnt1 , cnt2 ;
std::queue<int> a ;

int main()
{
	freopen("xor.in" , "r" , stdin) ;
	freopen("xor.out" , "w" , stdout) ;
	std::cin >> n >> k ;
	for(int i = 1 ; i <= n ; i++)
	{
		int t ;
		std::cin >> t ;
		if(t == 0) cnt0++ ;
		else cnt1++ ;
		a.push(t) ;
	}
	while(!a.empty())
	{
		int first = a.front() ;
		a.pop() ;
		if(first == 1 && a.front() == 1)
		{
			cnt2++ ;
			a.pop() ;
		} 
	}
	if(k == 1) std::cout << cnt1 << std::endl ;
	else std::cout << cnt2 + cnt0 << std::endl ; 
	return 0 ;
} 
