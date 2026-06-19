#include <bits/stdc++.h>

const int mod = 998224353 ; 
int a[10010] , n ;

bool check()
{
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i] != 1) return false ;
	}
	return true ; 
} 

int main()
{
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	std::cin >> n ;
	for(int i = 1 ; i <= n ; i++)
	{
		std::cin >> a[i] ;
	}
	if(n < 3)
	{
		std::cout << 0 << std::endl ;	
		return 0 ;
	} 
	if(n == 3)
	{
		int sum = a[1] + a[2] + a[3] ;
		int maxn = std::max(std::max(a[1] , a[2]) , a[3]) ;
		if(sum > 2 * maxn)
		{
			std::cout << 1 << std::endl ;
		}
		else
		{
			std::cout << 0 << std::endl ;
		}
		return 0 ;
	}
	if(check() == true)
	{
		long long ans = 1 ; 
		while(n--)
		{
			ans = ans * 2 % mod ;
		}	
		std::cout << ans << std::endl ;
		return 0 ;
	}  
	return 0 ;
}
