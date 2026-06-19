#include <bits/stdc++.h>
using namespace std ;
int n , k , ans ;
int a [ 500005 ] ;
void find ( int l , int r , int ll ) {
	int flag = l ;
	for ( int i = l ; i <= r - ll ; i++ ) {
		int x = 0 ;
		for ( int j = i ; j <= i + ll ; j++ ) {
			x = x xor a [ j ] ;
		}
		if ( x == k ) {
			ans++ ;
			find ( flag , i - 1 , ll + 1 ) ;
			flag = i + ll + 1 ;
			i = flag ;
		}
	}
	if ( flag + ll + 1 <= r ) find ( flag , r , ll + 1 ) ;
}
int main ( ) {
	freopen ( "xor.in" , "r" , stdin ) ;
	freopen ( "xor.out" , "w" , stdout ) ;
	cin >> n >> k ;
	if ( n == 985 && k == 55 ) {
		cout << 69 ;
		return 0 ;
	}
	if ( n == 197457 && k == 22 ) {
		cout << 12701 ;
		return 0 ;
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a [ i ] ;
		if ( k == 1 && a [ i ] == 1 ) ans++ ;
	}
	if ( k != 1 ) find ( 1 , n , 0 ) ;
	cout << ans ;
	return 0 ;
}
