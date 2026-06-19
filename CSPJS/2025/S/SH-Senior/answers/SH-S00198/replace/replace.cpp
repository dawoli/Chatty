#include<bits/stdc++.h>
using namespace std ;

int n ;
string s[200001][2] ;

string Slice( string str , int p , int l ) {
	string out = "" ;
	for( int i = 0 ; i < l ; ++i )
		out = out + str[ p + i ] ;
	return out ;
}

string change( string o , int p , string m ) {
	for( int i = 0 ; i < m.size() ; ++i )
		o[ p + i ] = m[i] ;
	return o ;
}

int main() {
	freopen( "replace.in" , "r" , stdin ) ;
	freopen( "replace.out" , "w" , stdout ) ;
	int q , ans , l , i = 0 , j ;
	string m , e ;
	scanf( "%d %d" , &n , &q ) ;
	for( ; i < n ; ++i )
		cin >> s[i][0] >> s[i][1] ;
	while( q-- ) {
		cin >> m >> e ;
		if( m.size() != e.size() ) {
			printf( "0\n" ) ;
			continue ;
		}
		l = m.size() ;
		ans = 0 ;
		for( i = 0 ; i < l ; ++i )
			for( j = 0 ; j < n ; ++j )
				if( l - i >= s[j][0].size() )
					if( Slice( m , i , s[j][0].size() ) == s[j][0] )
						if( change( m , i , s[j][1] ) == e )
							++ans ;
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}
