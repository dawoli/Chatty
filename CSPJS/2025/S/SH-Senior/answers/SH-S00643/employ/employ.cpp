#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read()
{
	ll f = 1,ans = 0;
	char ch = getchar();
	
	while( '0' > ch || ch > '9' )
	{
		if( ch == '-' )f = -1;
		ch = getchar();
	}
	
	while( '0' <= ch && ch <= '9' )
	{
		ans = ( ans << 1 ) + ( ans << 3 ) + ch - '0';
		ch = getchar();
	}
	
	return f * ans;
}

inline void write( ll x )
{
	if( x < 0 )putchar( '-' ),x = -x;
	if( x > 9 )write( x / 10 );
	putchar( x % 10 + '0' );
}

const ll mod = 998244353;
ll a[501],n,m;
//ll ans;
//bool vis[501];
//string s;
//
//void dfs( int dep , int cnt , int una )
//{
////	if( vis[i] )return;
////	cout << " " << cnt << " " << una << " " << dep << " " << ans << endl;
//	if( m - cnt > ( n - dep ) )return;
//	if( cnt >= m ){ans++,ans %= mod;return;}
//	if( dep == n )return;
//	
//	for( int i = 0 ; i < n ; i++ )
//	{
//		if( !vis[i] )
//		{
//			vis[i] = 1; 
//			if( s[dep] == '0' || una >= a[i] )dfs( dep + 1 , cnt , una + 1 );
//			else dfs( dep + 1 , cnt + 1 , una );
//			vis[i] = 0;
//		}
//	}
//}

ll b[501];

int main()
{
	freopen( "employ.in" , "r" , stdin );
	freopen( "employ.out" , "w" , stdout );
	
	ll n = read(),m = read(),ans = 0;
	string s;
	
	cin >> s;
	s = "0" + s;
	for( int i = 1 ; i <= n ; i++ )a[i] = read(),b[a[i]]++;
	
	sort( a + 1 , a + n + 1 );
	
//	dfs( 0 , 0 , 0 );
	
	do
	{
		int cur = 0,cnt = 0;
		for( int i = 1 ; i <= n ; i++ )
		{
			if( cur >= a[i] || s[i] == '0' )cur++;
			else cnt++;
//			cout << cnt << " " << cur << " "  << a[1] << " " << a[2] << " " << a[3] << endl;
			if( cnt >= m ){ans++,ans %= mod;break;}
		}
	}while( next_permutation( a + 1 , a + n + 1 ) );
	
	for( int i = 0 ; i <= n ; i++ )
	{
		if( b[i] )
		for( int j = 1 ; j<= b[i];j++ )
			ans *= j,ans %= mod;
	}
	
	cout << ans;
	
	return 0;
}
//8-20pts
