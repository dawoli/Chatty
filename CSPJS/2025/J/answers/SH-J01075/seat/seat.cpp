#include <bits/stdc++.h>
using namespace std ;
int n , m , a , b , c , lie , hang ;
int main ( ) {
	freopen ( "seat.in" , "r" , stdin ) ;
	freopen ( "seat.out" , "w" , stdout ) ;
	cin >> n >> m >> a ;
	for ( int i = 2 ; i <= n * m ; i++ ) {
		cin >> c ;
		if ( c > a ) b++ ;
	}
	lie = b / n + 1 ;
	if ( lie % 2 == 0 ) {
		hang = n - ( b % n ) ;
	}
	else {
		hang = b % n + 1 ;
	}
	cout << lie << ' ' << hang ;
	return 0 ;
}
