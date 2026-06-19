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

int fa[10040];

int find( int x )
{
	if( fa[x] == x )return x;
	return fa[x] = find( fa[x] );
}

struct node
{
	ll u,v,w;
}a[1200010];

ll kk[12],kn[12][10010];

ll cmp( node x , node y )
{
	return x.w < y.w;
}
	
int main()
{
	freopen( "road.in" , "r" , stdin );
	freopen( "road.out" , "w" , stdout );
	
	ll n = read(),m = read(),k = read();
	ll ans = 0,cnt = 0;
	
	for( int i = 1 ; i <= m ; i++ )a[i].u = read(),a[i].v = read(),a[i].w = read();
	for( int i = 1 ; i <= k ; i++ )
	{
		kk[i] = read();
		for( int j = 1 ; j <= n ; j++ )kn[i][j] = read();
	}
	sort( a + 1 , a + m + 1 , cmp );
	
	for( int i = 1 ;i <= n ;i++ )fa[i] = i;
	
	for( int i = 1 ; i <= m ; i++ )
	{
		int fx = find( a[i].u ),fy = find( a[i].v );
		if( fx != fy )
		{
			fa[fx] = fy;
			ans += a[i].w;
			cnt++;
			if( cnt == n - 1 )
			{
				break;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
//16pts
