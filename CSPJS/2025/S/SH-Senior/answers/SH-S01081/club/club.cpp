#include <bits/stdc++.h>
using namespace std ;
int t , n , a [ 5 ] [ 100005 ] , ans , b [ 100005 ] ;
void find ( int anss , int f , int ca , int cb , int cc ) {
	if ( f >= n ) {
		ans = max ( ans , anss ) ;
		//cout << f << ' ' << anss << ' ' << ca << cb << cc << endl ;
	}
	else {
	f++ ;
	if ( ca + 1 <= n / 2 ) find ( anss + a [ 1 ] [ f ] , f , ca + 1 , cb , cc ) ;
	if ( cb + 1 <= n / 2 ) find ( anss + a [ 2 ] [ f ] , f , ca , cb + 1 , cc ) ;
	if ( cc + 1 <= n / 2 ) find ( anss + a [ 3 ] [ f ] , f , ca , cb , cc + 1 ) ;
	}
}
int main ( ) {
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	cin >> t ;
	while ( t-- ) {
		cin >> n ;
		ans = 0 ;
		for ( int i = 1 ; i <= n ; i++ ) {
			cin >> a [ 1 ] [ i ] >> a [ 2 ] [ i ] >> a [ 3 ] [ i ] ;
			b [ i ] = a [ 1 ] [ i ] - a [ 2 ] [ i ] ;
			ans += a [ 2 ] [ i ] ;
		}
		if ( n <= 30 ) {
			ans = 0 ; 
			find ( 0 , 0 , 0 , 0 , 0 ) ;
			cout << ans << endl ;
		}
		else {
			sort ( b + 1 , b + n + 1 ) ;
			for ( int i = n / 2 + 1 ; i <= n ; i++ ) {
				ans += b [ i ] ;
			}
			cout << ans << endl ;
		}
	}
	return 0 ;
}
