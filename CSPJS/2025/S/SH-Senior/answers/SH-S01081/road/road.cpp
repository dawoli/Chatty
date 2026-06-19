#include <bits/stdc++.h>
using namespace std ;
int n , m , k , a [ 10005 ] [ 10005 ] , aa [ 100000005 ] , u , v , w ;
long long c , b [ 100005 ] ;
int main ( ) {
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
	cin >> n >> m >> k ;
	for ( int i = 1 ; i <= m ; i++ ) {
		cin >> u >> v >> w ;
		a [ u ] [ v ] = w ;
		a [ v ] [ u ] = w ;
	}
	for ( int l = 1 ; l <= k ; l++ ) {
		cin >> c ;
		for ( int i = 1 ; i <= n ; i++ ) {
			cin >> b [ i ] ;
			for ( int j = 1 ; j < i ; j++ ) {
				if ( b [ i ] + b [ j ] + c <= 1000000000 )
				if ( a [ i ] [ j ] == 0 ) a [ i ] [ j ] = b [ i ] + b [ j ] + c ;
				else a [ i ] [ j ] = min ( ( int ) ( b [ i ] + b [ j ] + c ) , a [ i ] [ j ] ) ;
			}
		}
	}
	int fl = 1 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j < i ; j++ ) {
			if ( a [ i ] [ j ] != 0 ) aa [ fl ] = a [ i ] [ j ] , fl++ ;
		}
	}
	sort ( aa + 1 , aa + fl ) ;
	long long ans = 0 ;
	for ( int i = 1 ; i < n ; i++ ) {
		ans += aa [ i ] ;
	}
	cout << ans ;
	return 0 ;
}

