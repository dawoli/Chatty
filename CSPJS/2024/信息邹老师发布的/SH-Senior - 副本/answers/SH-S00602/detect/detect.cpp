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

struct node
{
	int range_down,range_up;
	int range_down1,range_up1;
}car1[100001];

int det[100001],cf[100001];

bool cmp( node a , node b )
{
	if( a.range_down1 == b.range_down1 )
	{
		return a.range_up1 < b.range_up1;
	}
	
	return a.range_down1 < b.range_down1;
}

int main()
{
	freopen( "detect1.in" , "r" , stdin );
	freopen( "detect1.out" , "w" , stdout );
	
	int n,m,l,v,t = read(),i,ans,d,V,a,ans1;
	
	while( t-- )
	{
		memset( car1 , 0 , sizeof car1 );
		
		ans = 0,ans1 = 0;
		
		n = read();
		m = read();
		l = read();
		v = read();
		
		for( i = 1 ; i <= n ; i++ )
		{
			d = read();
			V = read();
			a = read();
			
			if( a < 0 )
			{
//				cout << V << " " << v << ' ';
//				cout << "1 " << car1[i].range_down << " " << car1[i].range_up << endl;
				if( V <= v )
				{
//					cout << "2 " << car1[i].range_down << " " << car1[i].range_up << endl;
					;
				}
				else
				{
//					cout << car1[i].range_down << " " << car1[i].range_up << endl;
					double tmp = double( v * v - V * V ) / double( 2 * a );
					
					if( floor( tmp ) - tmp <= 1e-6 && floor( tmp ) - tmp >= -1e-6 )
					{
						car1[i].range_up = -1;
					}
					
					car1[i].range_up = min( int( floor( tmp ) ) + d + car1[i].range_up , l );
					car1[i].range_down = d;
//					cout << "3 " << car1[i].range_down << " " << car1[i].range_up << endl;
				}
			}
			else if( a == 0 )
			{
				if( V <= v )
				{
					; 
				}
				else
				{
					car1[i].range_up = l;
					car1[i].range_down = d;
				}
			}
			else
			{
				if( V <= v )
				{
					double tmp = double( v * v - V * V ) / double( 2 * a );
					
					if( ceil( tmp ) - tmp <= 1e-6 && ceil( tmp ) - tmp >= -1e-6 )
					{
						car1[i].range_down = 1;
					}
					
					car1[i].range_down = min( int( ceil( tmp ) ) + d + car1[i].range_down , l );
					car1[i].range_up = l;
				}
				else
				{
					car1[i].range_up = l;
					car1[i].range_down = d;
				}
			}
			
//			cout << car1[i].range_down << " " << car1[i].range_up << endl;
		}
		
		for( i = 1 ; i <= m ; i++ )
		{
			det[i] = read();
		}
		
		bool flag;
		ll absdfk = 0;
		
		for( int j = 1 ; j <= n ; j++ )
		{
			flag = 0;
			
			for( i = 1 ; i <= m ; i++ )
			{
				if( car1[j].range_down <= det[i] && car1[j].range_up >= det[i] )
				{
					if( !flag )
					{ans++;
					car1[i].range_down1 = i;}
//					cout << i << endl;
flag = 1;car1[i].range_up1 = i;
					break;
				}
				
				if( !flag )
				{
					cf[i] = 0;
					
					absdfk++;
				}
				else
				{
					cf[i] = absdfk - 1;
					absdfk = 0;
				}
			}
		}
		
		cout << ans << " ";
		
		ll pre = 1;
		
		sort( car1 + 1 , car1 + ans + 1 , cmp );
		
		for( i = 1 ; i <= n ; i += cf[i] )
		{
			if( car1[i].range_down1 > pre )
			{
				ans1++;
				pre = car1[i - 1].range_up1 + 1 + cf[i];
			}
		}
		
		if( pre < ans )
		{
			ans1++;
		}
		
		cout << m - ans1 << endl;
	}
	
//	bool M2;
//	memory_output;
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
