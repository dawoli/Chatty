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

struct node
{
	ll x,y,z,t,ma;
}a[100005];

ll cmp( node x , node y )
{
	return x.ma > y.ma;
}

priority_queue < ll , vector<ll> , greater<ll> > qx;
priority_queue < ll , vector<ll> , greater<ll> > qy;
priority_queue < ll , vector<ll> , greater<ll> > qz;

int main()
{
	freopen( "club.in" , "r" , stdin );
	freopen( "club.out" , "w" , stdout );
	
	int t = read();
	
	while( t-- )
	{
		while( qx.size() )qx.pop();
		while( qy.size() )qy.pop();
		while( qz.size() )qz.pop();
		ll n = read(),ans = 0,cntx = 0,cnty = 0,cntz = 0;
		for( ll i = 1 ; i <= n ; i++ )
		{
			a[i].x = read(),a[i].y = read(),a[i].z = read();
				 if( a[i].x >= a[i].y && a[i].y >= a[i].z )a[i].t = a[i].x - a[i].y,a[i].ma = a[i].x;
			else if( a[i].x >= a[i].z && a[i].z >= a[i].y )a[i].t = a[i].x - a[i].z,a[i].ma = a[i].x;
			else if( a[i].y >= a[i].x && a[i].x >= a[i].z )a[i].t = a[i].y - a[i].x,a[i].ma = a[i].y;
			else if( a[i].y >= a[i].z && a[i].z >= a[i].x )a[i].t = a[i].y - a[i].z,a[i].ma = a[i].y;
			else if( a[i].z >= a[i].x && a[i].x >= a[i].y )a[i].t = a[i].z - a[i].x,a[i].ma = a[i].z;
			else if( a[i].z >= a[i].y && a[i].y >= a[i].x )a[i].t = a[i].z - a[i].y,a[i].ma = a[i].z;
		}
		sort( a + 1 , a + n + 1 , cmp );
		
		for( ll i = 1 ; i <= n ; i++ )
		{
//			cout << a[i].x << " " << a[i].y << " " << a[i].z << " " << a[i].ma << " " << a[i].t << endl;
			
			if( a[i].x == a[i].ma )
			{
				if( cntx == n / 2 )
					if( qx.top() < a[i].t )
					{
//						cout << qx.top() << " " << ans << " " << a[i].t << endl;
						ans -= qx.top();
						ans += a[i].x;
						qx.pop();
						qx.push( a[i].t );
					}
					else
						ans += max( a[i].y , a[i].z );
				else
				{
					cntx++;
					ans += a[i].x;
					qx.push( a[i].t );
				}
			}
			else if( a[i].y == a[i].ma )
			{
				if( cnty == n / 2 )
					if( qy.top() < a[i].t )
					{
//						cout << qy.top() << " " << ans << " " << a[i].t << endl;
						ans -= qy.top();
						ans += a[i].y;
						qy.pop();
						qy.push( a[i].t );
					}
					else
						ans += max( a[i].x , a[i].z );
				else
				{
					cnty++;
					ans += a[i].y;
					qy.push( a[i].t );
				}
			}
			else
			{
				if( cntz == n / 2 )
					if( qz.top() < a[i].t )
					{
//						cout << qz.top() << " " << ans << " " << a[i].t << endl;
						ans -= qz.top();
						ans += a[i].z;
						qz.pop();
						qz.push( a[i].t );
					}
					else
						ans += max( a[i].y , a[i].x );
				else
				{
					cntz++;
					ans += a[i].z;
					qz.push( a[i].t );
				}
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

//my name is harvey2019
//i had the idea in 14:46 and ACed in 15:37
//i love whoever watched this ouo
//finished on 18:20 i wish i can get 100+16+(30-40)+(8-20)=(154-176)pts
//114514 kkksc03 csp
