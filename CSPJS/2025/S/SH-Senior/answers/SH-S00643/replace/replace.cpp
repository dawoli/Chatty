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

string s1[200001],s2[200001];

int main()
{
	freopen( "replace.in" , "r" , stdin );
	freopen( "replace.out" , "w" , stdout );
	
	int n = read(),q = read();
	
	for( int i = 1 ; i <= n ; i++ )
		cin >> s1[i] >> s2[i];
	
	while( q-- )
	{
		string t1,t2;
		int ans = 0;
		
		cin >> t1 >> t2;
		int len1 = t1.size(),len2 = t2.size();
		
		if( len1 != len2 )
		{
			cout << 0 << endl;
			continue;
		}
		
		bool flag = 0;
		int pos1,pos2;
		for( int i = 0 ; i < len1 ; i++ )
		{
			if( t1[i] != t2[i] )
			{
				if( !flag )pos1 = i,flag = 1;
				if( flag )pos2 = i;
			}
		}
		
		string st1 = t1.substr( pos1 , pos2 - pos1 + 1 );
		string st2 = t2.substr( pos1 , pos2 - pos1 + 1 );
		
		for( int i = 1 ; i <= n ; i++ )
		{
			if( s1[i].find( st1 ) != -1 )
			{
				int pos3 = s1[i].find( st1 );
//				cout << pos3 << " " << i << " ";
				if( pos1 >= pos3 && pos1 - pos3 + s1[i].size() <= len1 )
				{
					string ss1 = t1.substr( pos1 - pos3 , s1[i].size() );
					string ss2 = t2.substr( pos1 - pos3 , s1[i].size() );
					
					if( ss1 == s1[i] && ss2 == s2[i] )ans++;
				}
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
//50pts
