#include "bits/stdc++.h"
using namespace std ;
int T, n ;
int solve(int x)
{
	int tmp = x % 7, tmp2 = x, flag = 0 ; x /= 7 ;
	if((tmp2 - 17) % 7 == 0 && tmp2 >= 17) cout << 200, x -= 2 ;
	else
	{
	if(tmp2 > 7) tmp2 = tmp2 % 7 + 7, x--, flag = 1 ;
	if(tmp2 == 10) cout << 22, flag = 0 ;
	else if(tmp == 3) cout << 7 ;
	if(tmp2 == 11) cout << 20, flag = 0 ;
	else if(tmp == 4) cout << 4 ;
	if(tmp == 2) cout << 1 ;
	if(tmp == 5) cout << 2 ;
	if(tmp == 6) cout << 6 ;
	}
	for(int i = 1 ; i <= x + flag ; ++i) cout << 8 ;
}
int main()
{
	freopen("sticks.in", "r", stdin) ;
	freopen("sticks.out", "w", stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; cout.tie(0) ;
	cin >> T ;
	for(int t = 1 ; t <= T ; ++t)
	{
		cin >> n ;
		if(n <= 1)
		{
			cout << -1 << endl ;
			continue ;
		}
		if(n % 7 == 0)
		{
			for(int i = 1 ; i <= n / 7 ; ++i) cout << 8 ;
			cout << endl ;
			continue ; 
		}
		if((n - 1) % 7 == 0)
		{
			cout << 10 ;
			for(int i = 1 ; i <= (n - 8) / 7 ; ++i) cout << 8 ;
			cout << endl ;
			continue ;
		}
		solve(n) ;
		cout << endl ;
	}
    return 0 ;
}
//AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC
//STO OTZ stO Orz STO OTZ stO Orz STO OTZ stO Orz
//AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC 
/*0 1 2 3 4 5 6 7 8 9*/
/*6 2 5 5 4 5 6 3 7 6*/
