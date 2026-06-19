#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	int n ;
	cin >> n ;
	int a[5010] ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
	}
	int m = 0 ;
	for(int i = 1 ; i <= n ; i++){
		m = max(m , a[i]) ;
		cout << m ;
	}
} 
