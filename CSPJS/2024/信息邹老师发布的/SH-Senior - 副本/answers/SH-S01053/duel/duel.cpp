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
int n , a[100001];
int main(){
	freopen( "duel.in" , "r" , stdin );
	freopen( "duel.out" , "w" , stdout );
	n = read();
	for( int i = 1 ; i <= n ; i++ ) a[i] = read();
	sort( a + 1 , a + n + 1 );
	int n1 = 0 , n2 = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( a[i] == 1 ) n1++;
		else n2++; 
	}
	int l = 1 , r = 1 , ans = n;
	while( true ){
		while( a[r] <= a[l] && r <= n ) r++;
		if( r > n ) break;
		r++; l++;
		ans--;
	}
	printf("%d\n",ans);
	fclose( stdin );
	fclose( stdout );
	return 0;
} 
