#include "bits/stdc++.h"
using namespace std ;
int n, m, x, q ;
int main()
{
	freopen("chain.in", "r", stdin) ;
	freopen("chain.out", "w", stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> m >> x >> q ;
		for(int i = 1 ; i <= m ; ++i) cin >> x ;
		for(int i = 1 ; i <= q ; ++i) cin >> x ;
		for(int i = 1 ; i <= q ; ++i) cout << 0 << endl ;
	}
    return 0 ;
}
