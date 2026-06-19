#include <bits/stdc++.h>
using namespace std ;
string s ;
int a [ 15 ] ;
int main ( ) {
	freopen ( "number.in" , "r" , stdin ) ;
	freopen ( "number.out" , "w" , stdout ) ;
	cin >> s ;
	for ( int i = 0 ; i < s.size ( ) ; i++ ) 
		if ( s [ i ] >= '0' && s [ i ] <= '9' ) a [ s [ i ] - '0' ]++ ;
	for ( int i = 1 ; i <= a [ 9 ] ; i++ ) cout << 9 ;
	for ( int i = 1 ; i <= a [ 8 ] ; i++ ) cout << 8 ;
	for ( int i = 1 ; i <= a [ 7 ] ; i++ ) cout << 7 ;
	for ( int i = 1 ; i <= a [ 6 ] ; i++ ) cout << 6 ;
	for ( int i = 1 ; i <= a [ 5 ] ; i++ ) cout << 5 ;
	for ( int i = 1 ; i <= a [ 4 ] ; i++ ) cout << 4 ;
	for ( int i = 1 ; i <= a [ 3 ] ; i++ ) cout << 3 ;
	for ( int i = 1 ; i <= a [ 2 ] ; i++ ) cout << 2 ;
	for ( int i = 1 ; i <= a [ 1 ] ; i++ ) cout << 1 ;
	for ( int i = 1 ; i <= a [ 0 ] ; i++ ) cout << 0 ;
	return 0 ;
}
