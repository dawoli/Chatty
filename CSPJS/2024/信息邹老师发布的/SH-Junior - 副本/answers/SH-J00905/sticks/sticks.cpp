#include<bits/stdc++.h>
using namespace std ;
int t , n ;
int a[50] = {-1 , -1 , 1 , 7 , 4 , 2 , 6 , 8 , 10 , 18 , 23 , 20 , 28 , 68 , 100 , 108 , 188 , 200 , 208 , 288,688,
888,1088,1888,2008,2088,2888,6888,8888,10888,18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,288888,688888,888888,1088888,1888888,2008888,2088888,2888888,6888888,8888888};
int main(){
	
	freopen("sticks.in" , "r" , stdin) ;
	freopen("sticks.out" , "w" , stdout) ;
	cin >> t ;
	for(int i = 1 ; i <= (t-1) ; i++){
		cin >> n ;
		if(n <= 35){
			cout << a[n] << endl ;
		}else if(n % 7 == 0){
			for(int j = 1 ; j <= (n/7) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}else if(n % 7 == 1){
			cout << 10 ;
			for(int j = 1 ; j <= (n/7-1) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}else if(n % 7 == 2){
			cout << 18 ;
			for(int j = 1 ; j <= (n/7-1) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}else if(n % 7 == 3){
			cout << 200 ;
			for(int j = 1 ; j <= (n/7-2) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}else if(n % 7 == 4){
			cout << 20 ;
			for(int j = 1 ; j <= (n/7-1) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}else if(n % 7 == 5){
			cout << 2 ;
			for(int j = 1 ; j <= (n/7) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}else if(n % 7 == 6){
			cout << 6 ;
			for(int j = 1 ; j <= (n/7) ; j++){
				cout << 8 ;
			}
			cout << endl ;
		}
	}
	cin >> n ;
	if(n <= 35){
		cout << a[n] ;
	}else if(n % 7 == 0){
		for(int j = 1 ; j <= (n/7) ; j++){
			cout << 8 ;
		}
	}else if(n % 7 == 1){
		cout << 10 ;
		for(int j = 1 ; j <= (n/7-1) ; j++){
			cout << 8 ;
		}
	}else if(n % 7 == 2){
		cout << 18 ;
		for(int j = 1 ; j <= (n/7-1) ; j++){
			cout << 8 ;
		}
	}else if(n % 7 == 3){
		cout << 200 ;
		for(int j = 1 ; j <= (n/7-2) ; j++){
			cout << 8 ;
		}
	}else if(n % 7 == 4){
		cout << 20 ;
		for(int j = 1 ; j <= (n/7-1) ; j++){
			cout << 8 ;
		}
	}else if(n % 7 == 5){
		cout << 2 ;
		for(int j = 1 ; j <= (n/7) ; j++){
			cout << 8 ;
		}
	}else if(n % 7 == 6){
		cout << 6 ;
		for(int j = 1 ; j <= (n/7) ; j++){
			cout << 8 ;
		}
	}
	
	return 0 ;
} 
