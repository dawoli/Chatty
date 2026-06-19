#include <bits/stdc++.h>
using namespace std;
int n,a[5002];
long long ans=0,mod=998244353;
map< int , int > m,mt;
map< int , int >::iterator mit;
void f1 () {
	ans=1;
	for ( int i=1 ; i<=n ; i++ ) {
		ans*=2;
		ans%=mod;
	}
	cout << ans;
	return ;
}
void f2 () {
	if ( a[1]+a[2]>a[3] ) cout << 1;
	else cout << 0;
	return ;
}
void f3 () {
	m[a[1]]+=1,m[a[2]]+=1,m[a[1]+a[2]]+=1;
	mt=m;
	for ( int i=3 ; i<=n ; i++ ) {
		m=mt;
		mit=m.begin() ;
		while ( !m.empty() and mit->first<=a[i] ) {
			m.erase( m.begin() ) ;
			mit=m.begin() ;
		}
		for ( mit=m.begin() ; mit!=m.end() ; mit++ ) {
			ans+=mit->second;
			ans%=mod;
		}
		m=mt;
		mt.clear() ;
		for ( mit=m.begin() ; mit!=m.end() ; mit++ ) {
			mt[mit->first+a[i]]=mit->second;
			mt[mit->first+a[i]]%=mod;
		}
		for ( mit=mt.begin() ; mit!=mt.end() ; mit++ ) {
			m[mit->first]+=mit->second;
			m[mit->first]%=mod;
		}
		m[a[i]]+=1;
		mt=m;
	}
	cout << ans;
	return ;
}
int main () {
	freopen ( "polygon.in" , "r" , stdin );
	freopen ( "polygon.out" , "w" , stdout );
	cin >> n;
	for ( int i=1 ; i<=n ; i++ ) cin >> a[i];
	sort ( a+1 , a+n+1 );
	if ( a[n]==1 ) f1 ();
	else if ( n==3 ) f2 ();
	else f3 ();
	return 0;
}
