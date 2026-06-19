#include<bits/stdc++.h>
using namespace std ;
long long n , r ;
long long a[1000005] ; 
int main(){
	
	freopen("duel.in" , "r" , stdin) ;
	freopen("duel.out" , "w" , stdout) ;
	cin >> n ;
	long long cnt1 = 0 ;
	long long cnt2 = 0 ;
	bool iff = 0 ;
	for(long long i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		if(a[i] != 2 && a[i] != 1){
			iff = 1 ;
		}
		if(a[i] == 2){
			cnt2++ ;
		}
		if(a[i] == 1){
			cnt1++ ;
		}
	}
	
	if(iff){
		cout << 2 ;
	}else{
		if(cnt2 >= cnt1){
			cout << n - cnt1 ;
		}else{
			cout << n - cnt2 ;
		}
	}

	return 0 ;
} 
