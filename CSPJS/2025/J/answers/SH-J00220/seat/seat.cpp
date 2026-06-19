#include <bits/stdc++.h>
using namespace std;
int n,m,a[102],ra,x=1,y=1,cnt=1;
bool f1 ( int t1 , int t2 ) {
	return t1>t2;
}
int main () {
	freopen ( "seat.in" , "r" , stdin );
	freopen ( "seat.out" , "w" , stdout );
	cin >> n >> m;
	for ( int i=1 ; i<=n*m ; i++ ) cin >> a[i];
	ra=a[1];
	sort ( a+1 , a+n*m+1 , f1 );
	for ( int i=1 ; (i-1)*2<=m ; i++ ) {
		for ( int j=1 ; j<n ; j++ ) {
			if ( a[cnt]==ra ) {
				cout << x << " " << y;
				return 0;
			}
			y++;
			cnt++;
		}
		if ( a[cnt]==ra ) {
			cout << x << " " << y;
			return 0;
		}
		x++;
		cnt++;
		for ( int j=1 ; j<n ; j++ ) {
			if ( a[cnt]==ra ) {
				cout << x << " " << y;
				return 0;
			}
			y--;
			cnt++;
		}
		if ( a[cnt]==ra ) {
			cout << x << " " << y;
			return 0;
		}
		x++;
		cnt++;
	}
	return 0;
}
