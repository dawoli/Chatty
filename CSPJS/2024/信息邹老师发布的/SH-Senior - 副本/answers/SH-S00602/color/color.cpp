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

int a[200001],n,dp[2001][2][2][2001];
//
//ll dp( int depth , int bl , int re )
//{
//	if( depth == n + 1 )
//	{
//		return 0;
//	}
//	
//	int cnt = 0;
//	
//	if( bl == d[i] )
//	{
//		
//	}
//	else
//	
//	return dp( depth + 1 ,  );
//}

int main()
{
	freopen( "color.in" , "r" , stdin );
	freopen( "color.out" , "w" , stdout );
	
	int t = read();
	
	while( t-- )
	{
		n = read();
		
		for( int i = 1 ; i <= n ; i++ )
		{
			a[i] = read();
		}
		
		for( int i = 1 ; i <= n ; i++ )
		{
			for( int j = 0 ; j < i ; j++ )
			{
				for( int k = i - j ; k < i ; k++ )
				{
					if( j == 0 )
					{
						dp[i][1][0][j] = dp[k][0][0][j - ( i - k )];
						dp[i][1][0][j] = dp[k][0][1][j - ( i - k )];
						dp[i][0][1][j] = dp[k][1][0][j - ( i - k )];
						dp[i][0][1][j] = dp[k][1][1][j - ( i - k )];
						dp[i][1][1][j] = dp[k][1][0][j - ( i - k )];
						dp[i][1][1][j] = dp[k][1][1][j - ( i - k )];
						dp[i][0][0][j] = dp[k][0][0][j - ( i - k )];
						dp[i][0][0][j] = dp[k][0][1][j - ( i - k )];
					}
					else
					{
						dp[i][1][0][j] = dp[k][0][0][j - ( i - k )];
						dp[i][0][1][j] = dp[k][1][1][j - ( i - k )];
						dp[i][1][1][j] = dp[k][1][1][j - ( i - k )];
						dp[i][0][0][j] = dp[k][0][0][j - ( i - k )];
					}
				}
			}
			
			for( int j = i - 1 ; j >= 1 ; j-- )
			{
				if( a[i] == a[j] )
				{
					for( int k = 0 ; k <= j ; k++ )
					{
						if( j == i - 1 )
						{
							dp[i][0][0][0] = max( dp[i][0][0][0] , dp[j][0][0][k] + a[i] );
							dp[i][0][0][0] = max( dp[i][0][0][0] , dp[j][0][1][k] + a[i] );
							dp[i][1][0][0] = max( dp[i][1][0][0] , dp[j][0][0][k] + a[i] );
							dp[i][1][0][0] = max( dp[i][1][0][0] , dp[j][0][1][k] + a[i] );
							dp[i][1][1][0] = max( dp[i][1][1][0] , dp[j][1][0][k] + a[i] );
							dp[i][1][1][0] = max( dp[i][1][1][0] , dp[j][1][1][k] + a[i] );
							dp[i][0][1][0] = max( dp[i][0][1][0] , dp[j][1][0][k] + a[i] );
							dp[i][0][1][0] = max( dp[i][0][1][0] , dp[j][1][1][k] + a[i] );
						}
						else
						{
							dp[i][1][0][i - j - 1] = max( dp[i][1][0][i - j - 1] , dp[j][1][1][k] + a[i] );
							dp[i][1][0][i - j - 1] = max( dp[i][1][0][i - j - 1] , dp[j][1][0][k] + a[i] );
							dp[i][0][1][i - j - 1] = max( dp[i][0][1][i - j - 1] , dp[j][1][1][k] + a[i] );
							dp[i][0][1][i - j - 1] = max( dp[i][0][1][i - j - 1] , dp[j][1][0][k] + a[i] );
						}
					}
				}
			}
		}
		
		int max1 = 0;
		
		for( int i = 0 ; i <= n ; i++ )
		{
			max1 = max( max1 , dp[n][1][0][i] );
			max1 = max( max1 , dp[n][0][1][i] );
			max1 = max( max1 , dp[n][1][1][i] );
			max1 = max( max1 , dp[n][0][0][i] );
		}
		
		cout << max1 << endl;
	}
	
	return 0;
}
