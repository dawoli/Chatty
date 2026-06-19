#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in" , "r" , stdin );
	freopen("poker.out" , "w" , stdout );
	int k;
	cin >> k;
	int poker[53];
	for ( int i = 0 ; i < 53 ; i ++ )
	{
		poker[i] = 0;
	}  
	for ( int e = 0 ; e < k ; e++ )
	{
		string n;
		cin >> n;
		int num = 0;
		char nf = n[0];
		char nd = n[1];
		if ( nf == 'D' ) num += 0; 
		if ( nf == 'C' ) num += 13; 
		if ( nf == 'H' ) num += 26; 
		if ( nf == 'S' ) num += 39; 
		if ( nd == 'T' ) num += 10;
		else if ( nd == 'A' ) num += 1;
		else if ( nd == 'J' ) num += 11;
		else if ( nd == 'Q' ) num += 12;
		else if ( nd == 'K' ) num += 13;
		else num += nd - 48;
		poker[num] = 1;
	}
	int ans = 0;
	for ( int i = 1 ; i < 53 ; i ++ )
	{
		ans += poker[i];
	}
	ans = 52 - ans;
	cout << ans;
	return 0;
} 
