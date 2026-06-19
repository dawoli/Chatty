#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long int llu ;

int n , m ;
bool s[501] ;
int c[501] ;
llu ans ;
bool flag = true ;

void init() {
	char C ;
	for( int i = 0 ; i < n ; ++i ) {
		cin >> C ;
		if( C == '1' )
			s[i] = true ;
		else
			flag = false ;
	}
	return ;
}

bool p() {
	int i = 1 ;
	for( ; i < n ; ++i )
		if( c[ i - 1 ] < c[i] )
			break ;
	if( i == n )
		return false ;
	
	
	
	return true ;
}

bool cmp( int x , int y ) {
	int f = 1 , p = 1 , i = 0 ;
	for( ; i < n ; ++i ) {
		if( p > m ) {
			++ans ;
			break ;
		}
		if( f > c[i] ) {
			++f ;
			continue ;
		}
		if( s[i] )
			++p ;
		else
			++f ;
	}
	if( ans == 998244353 )
		ans = 0 ;
	return x > y ;
}

int main() {
	freopen( "employ.in" , "r" , stdin ) ;
	freopen( "employ.out" , "w" , stdout ) ;
	scanf( "%d %d" , &n , &m ) ;
	init() ;
	int i = 0 , f , p ;
	for( ; i < n ; ++i )
		scanf( "%d" , &c[i] ) ;
	if( flag ) {
		ans = 1 ;
		++n ;
		for( i = 2 ; i < n ; ++i ) {
			ans *= i ;
			ans %= 998244353 ;
		}
		printf( "%llu\n" , ans ) ;
		return 0 ;
	}
	sort( c , c + n ) ;
	/*while( p() ) {//next_punctuation( c , c + n ) ) {
		f = 1 ;
		p = 1 ;
		for( i = 0 ; i < n ; ++i ) {
			if( p > m ) {
				++ans ;
				break ;
			}
			if( f > c[i] ) {
				++f ;
				continue ;
			}
			if( s[i] )
				++p ;
			else
				++f ;
		}
		if( ans == 998244353 )
			ans = 0 ;
	}*/
	sort( c , c + n , cmp ) ;
	printf( "%llu\n" , ans ) ;
	return 0 ;
} 
