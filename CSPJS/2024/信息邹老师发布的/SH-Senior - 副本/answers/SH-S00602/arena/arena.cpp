#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define memory_output cout<<endl,cerr<<(&M1-&M2)/1024.0/1024<<'\n'
bool M1;

inline ll read()
{
	ll x = 0,f = 1;
	char ch = getchar();
	
	while( '0' > ch || ch > '9' )
	{
		if( ch == '-' )
		{
			f = -1;
		}
		
		ch = getchar();
	}
	
	while( '0' <= ch && ch <= '9' )
	{
		x = ( x << 1 ) + ( x << 3 ) + ( ch - '0' );
		ch = getchar();
	}
	
	return x * f;
}

inline void write( ll x )
{
	if( x < 0 )
	{
		x = -x;
		putchar( '-' );
	}
	
	if( x > 9 )
	{
		write( x / 10 );
	}
	
	putchar( '0' + x % 10 );
}

int main()
{
//	freopen( "arena.in" , "r" , stdin );
//	freopen( "arena.out" , "w" , stdout );
	
	
	
	
	bool M2;
	memory_output;
	return 0;
}
