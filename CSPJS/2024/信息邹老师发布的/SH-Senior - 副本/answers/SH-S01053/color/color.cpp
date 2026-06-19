#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int N = 2e5 + 10;
int n;
int head[ N ] , nxt[ N << 1 ] , to[ N << 1 ] , val[ N << 1 ] , cnt = 0;

void add_edge( int u , int v , int w ){
	nxt[ ++cnt ] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	val[cnt] = w;
}
ll a[ N ] , pre[ 1000001 ] , dp[ N ] , qzh[ N ];
void mian(){
	n = read();
	
	memset( pre , 0 , sizeof(pre) );
	memset( dp , 0 , sizeof(dp) );
	memset( head , 0 , sizeof(head) );
	memset( nxt , 0 , sizeof(nxt) );
	memset( val , 0 , sizeof(val) );
	memset( qzh , 0 , sizeof(qzh) );
	cnt = 0; 
	
	for( int i = 2 ; i <= n ; i++ ) add_edge( i - 1 , i , 0 );
	for( int i = 1 ; i <= n ; i++ ){
		a[i] = read();
		qzh[i] += qzh[ i - 1 ];
		if( pre[ a[i] ] ){
			if( pre[ a[i] ] == i - 1 ) qzh[i] += a[i] , add_edge( i - 1 , i - 1  , a[i] );
			else add_edge( pre[ a[i] ] , i - 1 , a[i] + qzh[i] - qzh[ pre[ a[i] ] ] );
		}
		pre[ a[i] ] = i;
	}
	
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = head[i] ; j ; j = nxt[j] ){
			int v = to[j] , w = val[j];
			dp[v] = max( dp[i] + (ll)w , dp[v] );
		}
	}
	printf( "%lld\n" , dp[n] );
}
int main(){
	freopen( "color.in" , "r" , stdin );
	freopen( "color.out" , "w" , stdout );
	int T = read();
	while( T-- ) mian(); 
	fclose( stdin );
	fclose( stdout );
	return 0;
} 
