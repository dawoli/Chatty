#include <bits/stdc++.h>
using namespace std ;
int m , n ;
int g[1010] ;
int main(){
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n*m ; i++){
		cin >> g[i] ;
	}
	int R = g[1] ;
	if(n == 1 && m == 1){
		cout << "1" << " " << "1" ;
		return 0 ;
	}
	for(int i = 2 ; i<= n*m ; i++){
		for(int j = 1 ; j < n ; j++){
			if(g[j] < g[j+1]){
				int s = g[j] ;
				g[j] = g[j+1] ;
				g[j+1] = s ;
			}
		}
	}
	for(int i = 2 ; i<= n*m ; i++){
		for(int j = 1 ; j < n ; j++){
			if(g[j] < g[j+1]){
				int s = g[j] ;
				g[j] = g[j+1] ;
				g[j+1] = s ;
			}
		}
	}
	for(int i = 2 ; i<= n*m ; i++){
		for(int j = 1 ; j < n ; j++){
			if(g[j] < g[j+1]){
				int s = g[j] ;
				g[j] = g[j+1] ;
				g[j+1] = s ;
			}
		}
	}
	for(int i = 2 ; i<= n*m ; i++){
		for(int j = 1 ; j < n ; j++){
			if(g[j] < g[j+1]){
				int s = g[j] ;
				g[j] = g[j+1] ;
				g[j+1] = s ;
			}
		}
	}
	for(int i = 2 ; i<= n*m ; i++){
		for(int j = 1 ; j < n ; j++){
			if(g[j] < g[j+1]){
				int s = g[j] ;
				g[j] = g[j+1] ;
				g[j+1] = s ;
			}
		}
	}
	int number = 0 ;
	for(int i = 1 ; i <= n*m ; i++){
		if(g[i] == R ){
			number = i ;
		}
	}
	int lie = number/n + 1 ;
	int	hang = number%n ;
	if(lie%2 == 0){
		hang = n-hang ;
	}
	cout << lie <<" " << hang ;
	return 0 ;
} 
