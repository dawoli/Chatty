#include<bits/stdc++.h>
using namespace std ;
int t , n ;
int a[200005] ;

int main(){
	
	freopen("color.in" , "r" , stdin) ;
	freopen("color.out" , "w" , stdout) ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cin >> n ;
		int sum = 0 ;
		for(int j = 1 ; j <= n ; j++){
			cin >> a[j] ;
			for(int k = j-1 ; k >= 1 ; k--){
				if(a[j] == a[k]){
					sum += a[j] ;
					a[k] = -1 ;
					continue ;
				}
			}
		}
		cout << sum ;
		
	}
	
	
	return 0 ;
} 
