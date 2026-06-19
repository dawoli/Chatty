#include "bits/stdc++.h"
using namespace std ;
map<string, int> m ;
string s ;
int n, ans ;
int main()
{
	freopen("poker.in", "r", stdin) ;
	freopen("poker.out", "w", stdout) ;
	ios::sync_with_stdio(false) ; 
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> s ;
		if(!m[s]) ans++ ;
		m[s]++ ;
	}
	cout << 52 - ans << endl ;
	return 0 ;
}
//AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC
//STO OTZ stO Orz STO OTZ stO Orz STO OTZ stO Orz
//AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC AC 
