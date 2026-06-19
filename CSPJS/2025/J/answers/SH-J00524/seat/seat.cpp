#include <bits/stdc++.h> 

int n , m ;
int a[110] ;

int main()
{
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	std::cin >> n >> m ; 
	for(int i = 1 ; i <= n * m ; i++)
	{
		std::cin >> a[i] ;	
	} 
	int t = a[1] ;
	std::sort(a + 1 , a + (n * m) + 1) ; 
	int cnt = n * m + 1  ;
	for(int i = 1 ; i <= m ; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				cnt-- ;
				if(a[cnt] == t)
				{
					std::cout << i << " " << j << std::endl ;
					return  0 ;	
				}
			}
		}
		else
		{
			for(int j = n ; j >= 1 ; j--)
			{
				cnt-- ;
				if(a[cnt] == t)
				{
					std::cout << i << " " << j << std::endl ;
					return  0 ;	
				} 
			} 
		}
	}
}
