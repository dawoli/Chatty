#include <bits/stdc++.h>
using namespace std ;
int n , a [ 5005 ] ;
long long ans ;
int main ( ) {
	freopen ( "polygon.in" , "r" , stdin ) ;
	freopen ( "polygon.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a [ i ] ;
	}
	sort ( a + 1 , a + n + 1 ) ;
	if ( a [ n ] == 1 ) {
		for ( int i = 3 ; i <= n ; i++ ) {
			long long x = 0 ;
			for ( int j = n ; j > n - i ; j-- ) {
				x *= j ;
			}
			for ( int j = 1 ; j <= i ; j++ ) {
				x /= j ;
			}
			ans += x ;
			if ( ans >= 998244353 ) ans -= 998244353 ;
		}
		cout << ans % 998244353 ;
		return 0 ;
	}
	if ( n == 3 ) {
		if ( a [ 1 ] + a [ 2 ] > a [ 3 ] ) cout << 1 ;
		else cout << 0 ;
		return 0 ;
	}
	for ( int i = 1 ; i <= n ; i++ ) 
	for ( int j = i + 1 ; j <= n ; j++ ) 
	for ( int k = j + 1 ; k <= n ; k++ ) {
		if ( a [ i ] + a [ j ] > a [ k ] ) ans++ ;
		for ( int l = k + 1 ; l <= n ; l++ ) {
			if ( a [ i ] + a [ j ] + a [ k ] > a [ l ] ) ans++ ;
			for ( int o = l + 1 ; o <= n ; o++ ) {
				if ( a [ i ] + a [ j ] + a [ k ] + a [ l ] > a [ o ] ) ans++ ;
				for ( int p = o + 1 ; p <= n ; p++ ) {
					if ( a [ i ] + a [ j ] + a [ k ] + a [ l ] + a [ o ] > a [ p ] ) ans++ ;
					for ( int q = p + 1 ; q <= n ; q++ ) {
						if ( a [ i ] + a [ j ] + a [ k ] + a [ l ] + a [ o ] + a [ p ] > a [ q ] ) ans++ ;
						for ( int r = q + 1 ; r <= n ; r++ ) {
							if ( a [ i ] + a [ j ] + a [ k ] + a [ l ] + a [ o ] + a [ p ] + a [ q ] > a [ r ] ) ans++ ;
							for ( int s = r + 1 ; s <= n ; s++ ) {
								if ( a [ i ] + a [ j ] + a [ k ] + a [ l ] + a [ o ] + a [ p ] + a [ q ] + a [ r ] > a [ s ] ) ans++ ;
								for ( int t = s + 1 ; t <= n ; t++ ) {
									if ( a [ i ] + a [ j ] + a [ k ] + a [ l ] + a [ o ] + a [ p ] + a [ q ] + a [ r ] + a [ s ] > a [ t ] ) ans++ ;
								}
							}
						}
					}
				}
			}
		}
	}
	for ( int i = 11 ; i <= n ; i++ ) {
		long long x = 0 ;
		for ( int j = n ; j > n - i ; j-- ) {
			x *= j ;
		}
		for ( int j = 1 ; j <= i ; j++ ) {
			x /= j ;
		}
		ans += x ;
		if ( ans >= 998244353 ) ans -= 998244353 ;
	}
	cout << ans % 998244353 ;
	return 0 ;
}
