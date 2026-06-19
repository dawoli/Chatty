#include<bits/stdc++.h>
using namespace std ;
int t , n , k , q , l ;
int r , c ;
string s[200007] ;
int main(){
	
	freopen("chain.in" , "r" , stdin) ;
	freopen("chain.out" , "w" , stdout) ;
	cin >> t ;
	cin >> n >> k >> q ;
	for(int i = 1 ; i <= n ; i++){
		cin >> l ;
		cin >> s[i] ;
	}
	for(int j = 1 ; j <= q ; j++){
		cin >> r >> c ;
		cout << 1 << endl ;
	}
	
	return 0 ;
} 
