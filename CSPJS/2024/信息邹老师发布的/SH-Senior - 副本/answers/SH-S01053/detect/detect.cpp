#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0 , f = 1; char ch = getchar();
	while( ch < '0' || ch > '9' ){
		if( ch == '-' ) f = 0;
		ch = getchar();
	}
	while( ch >= '0' && ch <= '9' ){
		x = ( x << 1 ) + ( x << 3 ) + ch - '0';
		ch = getchar();
	}
	return f ? x : -x;
}
int n , m , L , V ;
int e[ 100001 ] , A[ 100001 ];
struct Node{
	int s , v , a;
	friend bool operator < ( const Node &a , const Node &b ){
		return a.s < b.s;
	}
}d[ 100001 ]; 
void mian(){
	n = read(); m = read(); L = read(); V = read();
	for( int i = 1 ; i <= n ; i++ ){
		d[i].s = read() , d[i].v = read() , d[i].a = read();
	} 
	for( int i = 1 ; i <= m ; i++ ){
		A[i] = read();
	}
	
	int ans1 = 0 , ans2 = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( d[i].v > V && d[i].s <= A[m] ) ans1++;
	}
	printf( "%d %d\n" , ans1 , m - 1 );
	return ;
}
int main(){
	freopen( "detect.in" , "r" , stdin );
	freopen( "detect.out" , "w" , stdout );
	int T = read();
	while( T-- ) mian();
	fclose( stdin );
	fclose( stdout );
	return 0;
} 
