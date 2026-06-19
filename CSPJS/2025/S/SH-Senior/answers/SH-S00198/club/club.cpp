#include<bits/stdc++.h>
using namespace std ;

int t , n , i , j , k ;
int a[100000][4] , sum[4] , les[3] , p[3] ;
	
int main() {
	freopen( "club.in" , "r" , stdin ) ;
	freopen( "club.out" , "w" , stdout ) ;
	scanf( "%d" , &t ) ;
	while( t-- ) {
		memset( a , 0 , sizeof(a) ) ;
		memset( sum , 0 , sizeof(sum) ) ;
		les[0] = 2e4 + 1 ;
		les[1] = 2e4 + 1 ;
		les[2] = 2e4 + 1 ;
		scanf( "%d" , &n ) ;
		for( i = 0 ; i < n ; ++i ) {
			scanf( "%d %d %d" , &a[i][0] , &a[i][1] , &a[i][2] ) ;
			if( a[i][0] >= a[i][1] && a[i][0] >= a[i][2] ) {
				a[i][3] = 0 ;
				++sum[0] ;
				sum[3] += a[i][0] ;
				if( a[i][0] < les[0] ) {
					les[0] = a[i][0] ;
					p[0] = i ;
				}
				else if( a[i][0] == les[0] ) {
					if( a[i][1] > a[ p[0] ][1] || a[i][2] > a[ p[0] ][2] ) {
						les[0] = a[i][0] ;
						p[0] = i ;
					}
				}
			}
			else if( a[i][1] >= a[i][0] && a[i][1] >= a[i][2] ) {
				a[i][3] = 1 ;
				++sum[1] ;
				sum[3] += a[i][1] ;
				if( a[i][1] < les[1] ) {
					les[1] = a[i][1] ;
					p[1] = i ;
				}
				else if( a[i][1] == les[1] ) {
					if( a[i][0] > a[ p[1] ][0] || a[i][2] > a[ p[1] ][2] ) {
						les[1] = a[i][1] ;
						p[1] = i ;
					}
				}
			}
			else {
				a[i][3] = 2 ;
				++sum[2] ;
				sum[3] += a[i][2] ;
				if( a[i][2] < les[2] ) {
					les[2] = a[i][2] ;
					p[2] = i ;
				}
				else if( a[i][2] == les[2] ) {
					if( a[i][1] > a[ p[2] ][1] || a[i][3] > a[ p[2] ][3] ) {
						les[2] = a[i][2] ;
						p[2] = i ;
					}
				}
			}
		}
		while( sum[0] > ( n >> 1 ) ) {
			if( a[ p[0] ][1] > a[ p[0] ][2] && sum[1] <= ( n >> 1 ) ) {
				a[ p[0] ][3] = 1 ;
				--sum[0] ;
				sum[3] -= a[ p[0] ][0] ;
				sum[3] += a[ p[0] ][1] ;
			}
			else {
				a[ p[0] ][3] = 2 ;
				--sum[0] ;
				sum[3] -= a[ p[0] ][0] ;
				sum[3] += a[ p[0] ][2] ;
			}
			les[0] == 2e4 + 1 ;
			for( i = 0 ; i < n ; ++i ) {
				if( a[i][3] == 0 ) {
					if( a[i][0] < les[0] ) {
						les[0] = a[i][0] ;
						p[0] = i ;
					}
					else if( a[i][0] == les[0] ) {
						if( a[i][1] > a[ p[0] ][1] || a[i][2] > a[ p[0] ][2] ) {
							les[0] = a[i][0] ;
							p[0] = i ;
						}
					}
				}
			}
		}
		while( sum[1] > ( n >> 1 ) ) {
			if( a[ p[1] ][0] > a[ p[1] ][2] && sum[0] <= ( n >> 1 ) ) {
				a[ p[1] ][3] = 0 ;
				--sum[1] ;
				sum[3] -= a[ p[0] ][1] ;
				sum[3] += a[ p[0] ][0] ;
			}
			else {
				a[ p[1] ][3] = 2 ;
				--sum[1] ;
				sum[3] -= a[ p[1] ][1] ;
				sum[3] += a[ p[1] ][2] ;
			}
			les[1] == 2e4 + 1 ;
			for( i = 0 ; i < n ; ++i ) {
				if( a[i][3] == 1 ) {
					if( a[i][1] < les[1] ) {
						les[1] = a[i][1] ;
						p[1] = i ;
					}
					else if( a[i][1] == les[1] ) {
						if( a[i][0] > a[ p[1] ][0] || a[i][2] > a[ p[1] ][2] ) {
							les[1] = a[i][1] ;
							p[1] = i ;
						}
					}
				}
			}
		}
		while( sum[2] > ( n >> 1 ) ) {
			if( a[ p[2] ][1] > a[ p[0] ][0] && sum[2] <= ( n >> 1 ) ) {
				a[ p[2] ][3] = 1 ;
				--sum[0] ;
				sum[3] -= a[ p[2] ][2] ;
				sum[3] += a[ p[2] ][1] ;
			}
			else {
				a[ p[2] ][3] = 0 ;
				--sum[2] ;
				sum[3] -= a[ p[2] ][2] ;
				sum[3] += a[ p[2] ][0] ;
			}
			les[2] == 2e4 + 1 ;
			for( i = 0 ; i < n ; ++i ) {
				if( a[i][3] == 2 ) {
					if( a[i][2] < les[2] ) {
						les[2] = a[i][2] ;
						p[2] = i ;
					}
					else if( a[i][2] == les[2] ) {
						if( a[i][1] > a[ p[2] ][1] || a[i][0] > a[ p[2] ][0] ) {
							les[2] = a[i][2] ;
							p[2] = i ;
						}
					}
				}
			}
		}
		printf( "%d\n" , sum[3] ) ;
	}
	return 0 ;
}
