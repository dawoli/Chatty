#include<bits/stdc++.h>
using namespace std ;
typedef unsigned long long int llu ;
typedef unsigned int u ;

int n , m , k ;
llu ans = 9e18 ;
int mp[10011][10011] ;
u w[1100001] , c[10011] ;
bool went[10011] ;

void dfs( int p , llu v ) {
	if( v > ans )
		return ;
	int i = 0 ;
	for( ; i < n ; ++i )
		if( !went[i] )
			break ;
	if( i == n ) {
		if( v < ans )
			ans = v ;
		return ;
	}
	for( i = 0 ; i < n + k ; ++i ) {
		if( mp[p][i] > -1 && !went[i] ) {
			went[i] = true ;
			dfs( i , v + w[ mp[p][i] ] + c[i] ) ;
			went[i] = false ;
		}
	}
	return ;
}

int main() {
	freopen( "road.in" , "r" , stdin ) ;
	freopen( "road.out" , "w" , stdout ) ;
	scanf( "%d %d %d" , &n , &m , &k ) ;
	int i = 0 , j , l ;
	for( ; i < n + k ; ++i )
		for( j = 0 ; j < n + k ; ++j )
			mp[i][j] = -1 ;
	for( i = 0 ; i < m ; ++i ) {
		scanf( "%d %d %u" , &j , &l , &w[i] ) ;
		--j ;
		--l ;
		mp[j][l] = i ;
		mp[l][j] = i ;
	}
	for( j = 0 ; j < k ; ++j ) {
		scanf( "%u" , &c[ j + n ] ) ;
		for( l = 0 ; l < n ; ++l ) {
			scanf( "%u" , &w[i] ) ;
			mp[l][ j + n ] = i ;
			mp[ j + n ][l] = i ;
			++i ;
		}
	}
	went[0] = true ;
	dfs( 0 , 0 ) ;
	printf( "%llu\n" , ans ) ;
	return 0 ;
} 
